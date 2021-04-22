#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "libguardaimagen.h"

#define REGLA 4 // [4, 32, 90, 94, 122, 150, 182]
#define N 1000 /* numero de celdas del ACE */
// #define N2 1000 /* segunda celda (solo defino para recordar 2 celdas!) */
#define T 500 /* numero de pasos de evolucion */

int main(int argc, char** argv)
{
    int i, j, nv, nv2, H;
    int and, norand;
    srand(time (NULL));  /* definicion del generador que utilizamos en este caso */
    double R, numRand;
    int ACE[ T+1 ][ N+2 ], ACE2[ T+1 ][ N+2 ];
    FILE *fileHamming;
    
    fileHamming = fopen("hamming_182.dat","w");
    
    numRand = rand();
    R = (numRand / (RAND_MAX + 1.0));
    
    /* definimos la condicion inicial de nuestro ACE */
    for (i = 0; i < T+1; i++)
    {
        for (j = 0; j < N+2; j++)
        {
            /* le ponemos la condicion que ponga seed segun el valor random */
            numRand = rand();
            R = (numRand / (RAND_MAX + 1.0));
         //   printf("%f\n", R); 
            if (R > 0.5) R = 1; else R = 0;
       //     printf("%f\n", R);
            /* las celdas tienen la misma configuracion incial */
            ACE[ i ][ j ] = R;
            ACE2[ i ][ j ] = R;
        }
    }
    ACE[ 0 ][ N/2 ] = 1; /* ponemos la semilla */
    ACE2[ 0 ][ N/2 ] = 0; // segunda celda tiene estado a N/2 diferente de 1era celda o sea 0
    /* simulamos los T primeros pasos de la evolucion del ACE */
    for (i = 1; i <  T+1; i++)
    {
        H = 0;
        for (j = 1; j < N+1; j++)
        {
            nv = (ACE[ i-1 ][ j+1 ] | ACE[ i-1 ][ j ] <<1 | ACE[ i-1 ][ j-1 ] <<2);
            nv2 = (ACE2[ i-1 ][ j+1 ] | ACE2[ i-1 ][ j ] <<1 | ACE2[ i-1 ][ j-1 ] <<2);
            /* tambien podiamos haber utilizado la expresion: */
            /*  nv = (2^2)*ACE[i-1][j-1]+(2^1)*ACE[i-1][j]+(2^0)*ACE[i-1][j+1]; */
             
             ACE[ i ][ j ] = (REGLA >> nv) & 1;
             ACE2[ i ][ j ] = (REGLA >> nv2) & 1;
             
            /* imponemos Hamming */
            // contruimos XOR
            and = ACE[ i ][ j ] & ACE2[ i ][ j ];
            norand = ~ACE[ i ][ j ] & ~ACE2[ i ][ j ];
            H += ~and & ~norand;
//            printf("%d\n", H);

        }
        
        fprintf(fileHamming, "%d %d \n", i, H);
            
        /* Actualizamos las condiciones periodicas de contorno */
        ACE[ i ][ 0 ] = ACE[ i ][ N ];
        ACE[ i ][ N+1 ] = ACE[ i ][ 1 ];
        ACE2[ i ][ 0 ] = ACE[ i ][ N ];
        ACE2[ i ][ N+1 ] = ACE[ i ][ 1 ];
    }
    
    guardaPGMi("ACE_R182_Randomseed.pgm", N+2, T+1, (int*)ACE, 1, 0);
    guardaPGMi("ACE2_R182_Randomseed.pgm", N+2, T+1, (int*)ACE2, 1, 0);

    fclose(fileHamming);
    
    return 0;
}
