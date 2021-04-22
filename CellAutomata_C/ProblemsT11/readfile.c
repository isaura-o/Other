#include <stdio.h>

int main(int argc, char** argv){
    
    int N, i, j; 
    double x[1000], y[1000];
    FILE* fin;
    
    fin = fopen("dades.dat","r");
    
    if(fin == NULL){perror("File error"); return 1;}
    
    i = 0;
    while (!feof(fin)) {
            /* loop through and store the numbers into the array */
            fscanf(fin, "%lf\t%lf\n", &x[i], &y[i]);
            i++;
    }
 
    printf("Number of numbers read: %d\n\n", i);
    printf("The numbers are:\n");
 
    printf("\nColumn 1:\n\n");
    for (j = 0; j < i; j++) {  
        printf("%f\n", x[j]);
    } 
    printf("\nColumn 2:\n\n");
    for (j = 0; j < i; j++) {
        printf("%f\n", y[j]);
    }
 
    fclose(fin);
    
    
    
    
    return 0;
}

