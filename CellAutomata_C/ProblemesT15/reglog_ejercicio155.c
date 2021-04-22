#include <stdio.h>
#include <math.h>


int main(int argc, char** argv){
    
    int N, i; 
    double x[1000], y[1000];
    double sumxy, sumx, sumy, sumx2, sum2x, sumy2, sum2y;
    double num, denY, denX, mx, my, r2, y0;
//    double logX[1000], logY[1000];
    FILE* fin;
    
    fin = fopen("hamming_182.dat","r"); //posar arxiu correcte!!!
    
    if(fin == NULL){perror("File error"); return 1;}
    
    i = 0;
    while (!feof(fin)) {
            fscanf(fin, "%lf\t%lf\n", &x[i], &y[i]);
            i++;
    }
    fclose(fin);
    
    N = i;  // printf("%d",N);
    
//    for(i=0;i<N;i++){
//        logX[i] = log10(x[i]);
//        logY[i] = log10(y[i]);
//        printf("%lf\t%lf\n", logX[i], logY[i]);
//    }
//    printf("%lf\t%lf\n", x[N-1], y[N-1]);
    
    sumxy = 0.0;
    for(i=0;i<N;i++)
        sumxy += log10(x[i])*log10(y[i]);
    
    sumx = 0.0;
    for(i=0;i<N;i++)
        sumx += log10(x[i]);
    
    sumx2 = (sumx)*(sumx);    
    
    sumy = 0.0;
    for(i=0;i<N;i++)
        sumy += log10(y[i]);
    
    sumy2 = (sumy)*(sumy);
    
    sum2x = 0.0;
    for(i=0;i<N;i++)
        sum2x += log10(x[i])*log10(x[i]);
        
    sum2y = 0.0;
    for(i=0;i<N;i++)
        sum2y += log10(y[i])*log10(y[i]);
    
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
