#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define REGLA 182 // [4 90 94 126 150 182]
#define N 10 /* Numero de celdas del ACE */
#define T 20 /* numero de pasos de evolucion */

int main(int argc, char** argv)
{
    int i, j, nv, estado, num_estado, cont;
    int ACE[T+1][N+2];
    FILE *fp;
    
    /* ahora definimos la matriz que guardar las veces que
     * se repita cada esado en el tiempo */
     
     fp = fopen("atractor_182.dat", "w");
     
     int prob[T+1][(int) pow(2,N)];
     
     for ( i = 0; i < T+1; i++)
     {
        for(j = 0; j < pow(2,N); j++)
        {
            prob[ i ][ j ] = 0;
        }
     }
     
     /* el primer bucle debe recorrer el espacio de fases
      * para proporcionar todos los estados iniciales posibles */
      
      for( estado = 0; estado < pow(2,N); estado++)
      {
        num_estado = 0;
        
        /* definimos el estado inicial del ACE */
        for(j = N-1; j >= 0; j--)
        {
            ACE[ 0 ][ N-j ] = (estado >> j ) & 1;
            
            /* Calculamos el numvero de estado */
            num_estado += ACE[ 0 ][ N-j ]*pow(2,j);
        } 
        
        /* añadimos una entrada en el contador del estado */
        prob[ 0 ][ num_estado ]++;
        
        /* actualizamos las condiciones periodicas de contorno */
        ACE[ 0 ][ 0 ] = ACE[ 0 ][ N ];
        ACE[ 0 ][ N+1 ] = ACE[ 0 ][ 1 ];
        
        /* simulamos los T primeros pasos de la evolucion del ACE */
        for( i=1; i < T+1; i++)
        {
            num_estado = 0;
            for (j = 1; j < N+1; j++)
            {
                nv = (ACE[ i-1 ][ j+1 ] | ACE[ i-1 ][ j ] << 1 | ACE[ i-1 ][ j-1 ] << 2);
                ACE[ i ][ j ] = (REGLA >> nv) & 1;
                num_estado += ACE[ i ][ j ]*pow(2,N-j);
            }
            
            prob[ i ][ num_estado ]++;
            
            /* actualizamos las consciones periodicas de contorno */
            ACE[ i ][ 0 ] = ACE[ i ][ N ];
            ACE[ i ][ N+1 ] = ACE[ i ][ 1 ];
        }
      }
      
      /* hacemos una prueba para verificar que lo que hemos hechos 
       * esta bien comprobando que en cada paso la suma de las 
       * visitas a todos los estados del espacio de fases es igual a 2^N */
       
       for(i=0; i < T+1; i++)
       {
            cont = 0;
            for (j = 0; j < pow(2,N); j++)
            {
                cont += prob[ i ][ j ];
            }
            
            if(cont != pow(2,N)) printf("ERROR EN EL PASO %d\n", i);
       }
       
       /* imprimimos los estados que han sido visitados alguna vez */
       for(i=0; i < T+1; i++)
       {
            for(j = 0; j < pow(2,N); j++)
            {
                if(prob[ i ][ j ]!= 0) printf("%d\t%d\n", j, i);
                if(prob[ i ][ j ]!= 0) fprintf(fp,"%d\t%d\n", j, i);
            }
       }
    
    fclose(fp);
    return 0;
}
