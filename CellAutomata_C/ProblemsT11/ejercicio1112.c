#include <stdio.h>
#include <math.h>


int main(int argc, char** argv){
    
    int N, i; 
    double x[1000], y[1000];
    double sumxy, sumx, sumy, sumx2, sum2x, sumy2, sum2y;
    double num, denY, denX, mx, my, r2, y0;
    FILE* fin;
    
    fin = fopen("dades.dat","r");
    
    if(fin == NULL){perror("File error"); return 1;}
    
    i = 0;
    while (!feof(fin)) {
            /* loop through and store the numbers into the array */
            fscanf(fin, "%lf\t%lf\n", &x[i], &y[i]);
            i++;
    }
    fclose(fin);
    
    N = i;  // printf("%d",N);
    
    sumxy = 0.0;
    for(i=0;i<N;i++)
        sumxy += x[i]*y[i];
    
    sumx = 0.0;
    for(i=0;i<N;i++)
        sumx += x[i];
    
    sumx2 = (sumx)*(sumx);    
    
    sumy = 0.0;
    for(i=0;i<N;i++)
        sumy += y[i];
    
    sumy2 = (sumy)*(sumy);
    
    sum2x = 0.0;
    for(i=0;i<N;i++)
        sum2x += x[i]*x[i];
        
    sum2y = 0.0;
    for(i=0;i<N;i++)
        sum2y += y[i]*y[i];
    
    num = (N*sumxy) - (sumx*sumy);
    denY = (N*sum2x)-sumx2;
    denX = (N*sum2y)-sumy2;
    my = num/denY;
    mx = num/denX;    
    r2 = mx*my;
    y0 = (sumy - (my*sumx))/N;
    
    printf("N = %d\n",N);
    printf("sum_x = %lf\n", sumx);
    printf("sum_y = %lf\n", sumy);
    printf("mean_x = %lf\n", sumx/N);
    printf("mean_y = %lf\n", sumy/N);
    printf("sum_xy = %lf\n", sumxy);
    printf("(sum_x)^2 = %lf\n", sumx2);
    printf("(sum_y)^2 = %lf\n", sumy2);  
    printf("sum_x^2 = %lf\n", sum2x);
    printf("sum_y^2 = %lf\n", sum2y); 
   // printf("%lf\t%lf\t%lf\n", num, denY, denX); 
    printf("r2 = %lf, r= %lf\n",r2, sqrt(r2)); 
    printf("a = %lf, b= %lf \n", my, y0);
    
    return 0;
}
