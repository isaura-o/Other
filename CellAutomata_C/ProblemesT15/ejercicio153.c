#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main(int argc, char** argv)
{
    int a, b;
    srand(time (NULL));
    /* Valores aleatorios entre [a,b]: 
     * P = rand()/(max_val+1) --> esto es entre [0,1] para ponerlo entre el rango de a i b:
     * el dominio vendra dado por: x = b-a, donde estamos poniendo a a zero!! */
    double rango = b - a + 1;       /* rango donde se encuentra mis valores, teniendo en cuenta que b > a */
    double numRand, R1, R;      

    scanf("%d %d",&a,&b);
    
    /* segun los apuntes: */
    numRand = rand();
    R1 = (numRand / (RAND_MAX + 1.0)) * rango;
    
    /* Al haber puesto a a zero ahora se lo sumamos! (asi ira de a->b i no de 0 ->b-a!!) */
    R = a + R1;
    
   /* printf("%f %d\n", numRand, RAND_MAX); */
    printf("Result from equation: %f\n", R1);
    printf("Result in the range [%d, %d] : %f\n", a, b, R);
    
    return 0;
}
