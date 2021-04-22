#include <stdio.h>

int main(int argc, char** argv){
    
    int i, j, *q;
    int M[3][3];
    
    /* diferentes formas de definir los elementos de
     * la matriz M mediente punteros y vectores */
     
     q=&M[1][0];
     
     **M = 1;       /* M[0][0] = 1 */
     *(*M+1) = 2;   /* M[0][1] = 2 */
     (*M)[2] = 3;   /* M[0][2] = 3 */
     **(M+1) = 4;   /* M[1][0] = 4 */
     *(M[1]+1) = 5; /* M[1][1] = 5 */
     *(*(M+1)+2) = 6; /* M[1][2] = 6 */
     *(M+2)[0] = 7; /* M[2][0] = 7 */
     *(q+4) = 8;    /* M[2][1] = 8 */
     q[5] = 9;      /* M[2][2] = 9 */
     
     for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf(" %d", M[i][j]);
        }
        printf("\n");
    } 
    return 0;    
}
