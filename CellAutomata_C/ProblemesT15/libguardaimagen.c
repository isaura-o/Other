#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "libguardaimagen.h"


void guardaPGMi (char* nombre, int anchura, int altura, int *pixels, int pixel_min, int pixel_max)
{
    int i, j, ij, p;
    FILE* imagen;
    imagen = fopen(nombre, "wb");
    fprintf(imagen, "P2");
    fprintf(imagen, "#guardaPGMi %s\n", nombre);
    fprintf(imagen, "%d %d\n", anchura, altura);
    fprintf(imagen, "255\n");
    ij = 0;
    for (i=0; i<altura; i++)
    {
        for (j=0; j<anchura; j++)
        {
            p= (255*(pixels[ ij ]-pixel_min)) / (pixel_max-pixel_min);
            if ( p<0 ) p=0;
            if ( p>255) p=255;
            fprintf (imagen, " %d", p);
            ij++;
        }
        fprintf (imagen, "\n");
    }
    fclose (imagen);
}

void guardaPGMd (char* nombre, int anchura, int altura, double *pixels, double pixel_min, double pixel_max)
{
    int i, j, ij, p;
    FILE* imagen;
    imagen = fopen(nombre, "wb");
    fprintf(imagen, "P2");
    fprintf(imagen, "#guardaPGMi %s\n", nombre);
    fprintf(imagen, "%d %d\n", anchura, altura);
    fprintf(imagen, "255\n");
    ij=0;
    for (i=0; i<altura; i++)
    {
        for (j = 0; j < anchura; j++)
        {
            p = (int)((255.0 * (pixels[ij] - pixel_min)) / (pixel_max - pixel_min));
            if ( p<0 ) p=0;
            if ( p>255) p=255;
            fprintf (imagen, " %d", p);
            ij++;
        }
        fprintf (imagen, "\n");
    }
    fclose (imagen);
}


void logreg(char *filename, double *my, double *y0, double *r2)
{
    int leng, k; 
    double x[100000], y[100000];
    double sumxy, sumx, sumy, sumx2, sum2x, sumy2, sum2y;
    double numera, denY, denX, mx;//, my, r2, y0;
    FILE* fin;
    
    fin = fopen(filename,"r+"); //posar arxiu correcte!!!
    
   // if(filename == NULL){perror("File error"); return 1;}
    
    k = 0;
    while (!feof(fin)) {
            fscanf(fin, "%lf\t%lf\n", &x[k], &y[k]);
            k++;
    }
    fclose(fin);
    leng = k; 
    
    sumxy = 0.0;
    for(k=0;k<leng;k++)
        sumxy += log10(x[k])*log10(y[k]);
    
    sumx = 0.0;
    for(k=0;k<leng;k++)
        sumx += log10(x[k]);
    
    sumx2 = (sumx)*(sumx);    
    
    sumy = 0.0;
    for(k=0;k<leng;k++)
        sumy += log10(y[k]);
    
    sumy2 = (sumy)*(sumy);
    
    sum2x = 0.0;
    for(k=0;k<leng;k++)
        sum2x += log10(x[k])*log10(x[k]);
        
    sum2y = 0.0;
    for(k=0;k<leng;k++)
        sum2y += log10(y[k])*log10(y[k]);
    
    numera = (leng*sumxy) - (sumx*sumy);
    denY = (leng*sum2x)-sumx2;
    denX = (leng*sum2y)-sumy2;
    *my = numera/denY;
    mx = numera/denX;    
    *r2 = sqrt(mx*(*my));
    *y0 = (sumy - ((*my)*sumx))/leng;
}
