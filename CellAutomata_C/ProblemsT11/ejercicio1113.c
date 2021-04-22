#include <stdio.h>
#include <math.h>

void producto(double *p, double *V, double *MxV, double *modulo)
{
    int i, j;
    double M[10][10];
    
    // Calculamos el producto de la matriz y el vector
    for(i=0;i<2;i++)
    {
        *(MxV+i) = 0;
        for(j=0;j<3;j++)
        {
            M[i][j] = *(*(p+i)+j);
            *(MxV+i) += M[i][j]*V[j];
        }
    }
    
    // Calculamos el modulo del vector resultante
    for(i=0; i<2; i++)
         *modulo += pow(*(MxV+i),2);
        
    *modulo += sqrt(*modulo);
    
    return;
}

int main(int argc, char** argv)
{
    double *M, Me[2][3] = {{1.,1.,1.},{1.,1.,1.}};
    double Ve[3] = {1,2,3},*V;
    double MxV, modulo;
    
    *V=&Ve;
    *M = &M;
    
    producto(M, V, MxV, &modulo);
    
    printf("El producto de la matriz M por el vector V"
            " es (%g, %g)\n", MxV[0],MxV[1]);
            
    printf("El modulo del vector es %f\n", modulo);
    
    return 0;
}
