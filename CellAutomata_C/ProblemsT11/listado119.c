#include <stdio.h>

int main(int argc, char** argv)
{
    int v[6];
    int *q;
    
    /* asignamos al puntero q la direccion de memoria
     * del primer elemento del vector */
     q=v;
     
     /* tambien podriamos haber hecho q=&v[0] */
     *v = 0; // v[0] = 0
     v[1] = 1; // v[1] = 1
     q[2] = 2; // v[2] = 2
     *(q+3) = 3; // v[3] = 3
     *(v+4) = 4; // v[4] = 4
     *(&v[5]) = 5; // v[5] = 5
     
     printf("El vector es: {%d, %d, %d, %d, %d, %d}\n",
            v[0], v[1], v[2], v[3], v[4], v[5]);
     
     return 0;       
}
