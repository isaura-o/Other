// Calcular el producto de dos matricies de numeros reales 3x3
// una de ellas codificada en el programa y la otra pedida a partir
// scanf.
#include <stdio.h>

int main(int argc, char** argv)
{
    int i, j, k;
    double m1[3][3], m2[3][3], m3[3][3];
    
   /* m1[0][0] = 1.0;
    m1[0][1] = 0.0;
    m1[0][2] = 0.0;
    m1[1][0] = 0.0;
    m1[1][1] = 1.0;
    m1[1][2] = 0.0;
    m1[2][0] = 0.0;
    m1[2][1] = 0.0;
    m1[2][2] = 1.0;
    */
    
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(i==j){
                m1[i][j] = 1;
            }else{
                m1[i][j] = 0;
            }
        }
    }
    
   /* printf("Entra la primera matriu:\n");
    for ( i=0; i<3; i++)
        for(j=0;j<3;j++)
            scanf("%lf", &m1[i][j]);
    */
    printf("matriu prova:\n");
    for (i=0; i<3; i++){   
        printf("[");
        for(j=0; j<3; j++){ 
            printf("%lf ", m1[i][j]);
        }
        printf("]\n");
    }
    
    printf("Entra la segona matriu:\n");
    for ( i=0; i<3; i++)
        for(j=0;j<3;j++)
        scanf("%lf", &m2[i][j]);

    // multiplicacio
  //  sum = 0.0;
    for (i=0; i<3;i++){
        for(j=0;j<3;j++){
            m3[i][j] = 0.0;
            for(k=0; k<3; k++){
                m3[i][j] = m3[i][j] + (m1[i][k]*m2[k][j]);
            }
         //   m3[i][j] = sum;
         //   sum = 0.0;
        }
    }
    
    
    printf("Matriu final:\n");
    for (i=0; i<3; i++){   
        printf("[");
        for(j=0; j<3; j++){ 
            printf("%lf ", m3[i][j]);
        }
        printf("]\n");
    } 

    return 0;
}
