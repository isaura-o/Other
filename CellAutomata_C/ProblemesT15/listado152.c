#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 5 /* tamaño del ACE */

int main(int argc, char** argv)
{
    int estado, j;
    
    for(estado = 0; estado < pow(2,N); estado++)
    {
        printf("estdo %d: (" , estado);
        for (j =N-1; j >= 0; j--)
        {
            printf("%d", (estado >> j) & 1);
        }
        printf(")\n");
    }
    
    return 0;
}
