#include <stdio.h>
#include <math.h>

double regressionLineal(int npts, double x[], double y[], double *_m, double *_y0)
{
    int i;
    double sumxy, sumx, sumy, sum2x, sumx2, sum2y, sumy2;
    double num, denX, denY, r2, mx;
    
    
    sumxy = 0.0;
    for(i=0;i<npts;i++)
        sumxy += x[i]*y[i];
    
    sumx = 0.0;
    for(i=0;i<npts;i++)
        sumx += x[i];
    
    sumx2 = (sumx)*(sumx);    
    
    sumy = 0.0;
    for(i=0;i<npts;i++)
        sumy += y[i];
    
    sumy2 = (sumy)*(sumy);
    
    sum2x = 0.0;
    for(i=0;i<npts;i++)
        sum2x += x[i]*x[i];
        
    sum2y = 0.0;
    for(i=0;i<npts;i++)
        sum2y += y[i]*y[i];
    
    
    num = (npts*sumxy) - (sumx*sumy);
    denY = (npts*sum2x)-sumx2;
    denX = (npts*sum2y)-sumy2;
    *_m = num/denY;
    mx = num/denX;    
    r2 = (*_m)*mx;
    *_y0 = (sumy - ((*_m)*sumx))/npts;
    
    return r2;
}

int main(int argc, char** argv){
    
    int N, i; 
    double x[1000], y[1000];
    double rSquare, my, y0;
    FILE* fin;
    
    fin = fopen("dades.dat","r");
    
    if(fin == NULL){perror("File error"); return 1;}
    
    i = 0;
    while (!feof(fin)) {
            fscanf(fin, "%lf\t%lf\n", &x[i], &y[i]);
            i++;
    }
    fclose(fin);
    
    N = i;  // printf("%d",N);
    
    rSquare = regressionLineal(N, x, y, &my, &y0);
    
    
    
    printf("N = %d\n",N);
    printf("r2 = %lf, r= %lf\n",rSquare, sqrt(rSquare)); 
    printf("a = %lf, b= %lf \n", my, y0);
    
    return 0;
}
