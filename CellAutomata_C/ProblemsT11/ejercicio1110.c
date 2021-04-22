/* Calculo los puntos que dividen [0,1] en 100 subintervarlos*/
#include <stdio.h>

int main(int argc, char** argv)
{
    int i;
    float a, b, c;
    
    a = 0;
    b = 1;
    c = (b-a)/100; // longitud intervals
    
    i = 1;
    while( c<=1  )
    {
        printf("interval num = %d, value= %f\n",i,c);
        c += 0.01;
        i++;
    }
    return 0;
}    
