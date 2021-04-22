#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "libguardaimagen.h"

#define REGLA 182 // [4, 32, 90, 94, 122, 150, 182]
#define N 500 /* numero de celdas del ACE */
#define T 500 /* numero de pasos de evolucion */

int main(int argc, char** argv)
{
    int i, j, nv;
    srand(time (NULL));  /* definicion del generador que utilizamos en este caso */
    double R, numRand;
    int ACE[ T+1 ][ N+2 ];
    

    
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
            ACE[ i ][ j ] = R;
            
        }
    }
    ACE[ 0 ][ N/2 ] = 1; /* ponemos la semilla */
    /* simulamos los T primeros pasos de la evolucion del ACE */
    for (i = 1; i <  T+1; i++)
    {
        for (j = 1; j < N+1; j++)
        {
            nv = (ACE[ i-1 ][ j+1 ] | ACE[ i-1 ][ j ] <<1 | ACE[ i-1 ][ j-1 ] <<2);
            /* tambien podiames haver utilizado la expresion: */
            /*  nv = (2^2)*ACE[i-1][j-1]+(2^1)*ACE[i-1][j]+(2^0)*ACE[i-1][j+1]; */
             
             ACE[ i ][ j ] = (REGLA >> nv) & 1;
        }
        /* Actualizamos las condiciones periodicas de contorno */
        ACE[ i ][ 0 ] = ACE[ i ][ N ];
        ACE[ i ][ N+1 ] = ACE[ i ][ 1 ];
    }
    
    guardaPGMi("ACE_R182_Randomseed.pgm", N+2, T+1, (int*)ACE, 1, 0);
    
    return 0;
}
