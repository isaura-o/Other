/* Calculo los puntos que dividen [0,1] en 100 subintervarlos*/
#include <stdio.h>

int main(int argc, char** argv)
{
    int i;
    float a, b, c;
    
    a = 0;
    b = 1;
    c = (b-a)/100; // longitud intervals
    
    for (i=1; c<=1; i++)
    {
        printf("interval num = %d, value= %f\n",i,c);
        c += 0.01;
    }
    return 0;
}    
    /* amb el bucle while
    i = 1;
    while( c <= 1 )
    {
      printf("intervalo num =%d, es %f\n", i, c);
      c += 0.01;
      i++;    
    }
    
    return 0;
}
*/
