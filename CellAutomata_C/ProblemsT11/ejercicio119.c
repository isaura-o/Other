// calcular los numeros pares menores que 10 a partir del programa 11.8
#include <stdio.h>


int main(int argc, char** argv)
{
    int i, a;
    
    a = 0;   
    while( a<10 )
    {
        a += 1;
        i++;
        if ( a % 2 == 0 )
        {
            printf("value= %d\n",a);
        }

    }
    
    return 0;
}
