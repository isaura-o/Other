#include <stdio.h>
#include <math.h>

void producto(double M[][3], double V[], double MxV[], double *modulo)
{
    int i, j;
    
    // Calculamos el producto de la matriz y el vector
    for(i=0;i<2;i++)
    {
        MxV[i] = 0;
        for(j=0;j<3;j++)
        {
            MxV[i]+=M[i][j]*V[j];
        }
    }
    
    // Calculamos el modulo del vector resultante
    for(i=0; i<2; i++)
        *modulo += MxV[i]*MxV[i];
        
    *modulo += sqrt(*modulo);
    
    return;
}

int main(int argc, char** argv)
{
    double M[2][3] = {{1.,1.,1.},{1.,1.,1.}};
    double V[3] = {1,2,3};
    double MxV[2], modulo;
    
    producto(M,V,MxV, &modulo);
    
    printf("El producto de la matriz M por el vector V"
            " es (%g, %g)\n", MxV[0], MxV[1]);
            
    printf("El modulo del vector es %f\n", modulo);
    
    return 0;
}
