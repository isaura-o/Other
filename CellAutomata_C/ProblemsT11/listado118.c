#include <stdio.h>

int main(int argc, char** argv)
{
    double a = 43.4;
    double *q;
    
    /* asignamos al puntero q la direccion de memoria de la variable a */
    q=&a;
    
    /* resultado el valor de a */
    printf("El puntero q apunta al valor %lg\n", *q);
    
    /* modificamos el valor de la variable a la que apunta el puntero q*/
    *q=0.3;
    
    /* resultado en nuevo valor */
    printf("El puntero q apunta al valor %lg\n", *q);
    
    /* como la variable "a" esta en la misma direccion de memoria*/
    printf("El nuevo valor de a es %lg\n",a);
    
    return 0;
}
