#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double division(double a, double b)
{
    return (a/b);
}

double multiplication(double a,double b)
{
    return (a*b);
}

double oper(double a, double b, double (*operation)(double, double))
{
    return operation(a,b);
}

int main(int argc, char** argv)
{
    double a,b;
    char *c;
    
    a = atof(argv[1]);
    b = atof(argv[2]);
    c = argv[3];
    
    if(!strcmp(c, "multiplicar"))
        printf("el resultado de %s %g por %g es %g\n",
                c, a, b, oper(a,b,&multiplication));
    else            
    if(!strcmp(c, "dividir"))
        printf("el resultado de %s %g por %g es %g\n",
                c, a, b, oper(a,b,&division));
    else
        printf("La operacion no ha sido debidamente introducida");
        
    return 0;
}
