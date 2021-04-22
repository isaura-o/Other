#include <stdio.h>

/** PROGRAMA PI
 * Calcula 1002 cifras decimales del numero PI
 * Algoritmo: pi3
 * Referencia: (buscarla)
 * Autor: (anonimo); Adaptacion: DRP
 * Fecha: 20/10/2010
 * Observaciones: antes era asi
 * long k= 4e3, p, a[337], q, t= 1e3;
 * main(j){for(; a[j=q=0]+=2,--k;)
 * for(p=1+2*k;j<337;q=a[j]*k+q%p*t,a[j++]=q/p)
 * k!=j>2?:printf("%.3d",a[j-2]%t+q/p/t);}
 */
 
 int main(int argc, char** argv){
    long k=4000; /*cuatro mil */
    long t=1000; /*mil */
    long a[337]; /*array de resultados parciales*/
    long p;     /* denominador de la serie modular */
    long q;     /* numerador de la serie modular */
    long d;     /* variable auxiliar */
    int j;      /*contador */
    
    /*PI=3. ... */
    printf("PI=3.");
    
    /*Bucle principal
     * Nota: solo imprime ternas de cifras en los
     *  ultimos dos pasos de calculo
     */
    
    while(k>1)
    {
        k--;    /* paso del bucle de impresion */
        q=0;    /*inicializar contador modular */
        
        a[0]+=2; /*avanzar en a[0] por cada k */
        p=1+2*k; /* inicializar el denominador 
                    de la serie modular */
        
        /*bucle de calculo de a[]*/
        for(j=0;j<337;j++)
        {
            /*condicion de calculo completado:
             * dos ultimos paos en k */
             if( (j>2 && k== 1) || k==0 )
             {
                /*todas las divisiones son enteras*/
                d=a[j-2]%t+(q/p)/t;
                
                /*imprimir las siguientes 3 cifras*/
                printf("%.3ld",d);
             }
             /*actualizar el numerador de la serie*/
             q=a[j]*k+q%p*t;
             /*guardar el valor en a (se utilizara dos j-pasos 
              * mas adelante)*/
            a[j]=q/p;
        }
        
    }
    /* salto de linea final */
    printf("\n");
    
    /*Informar al SO de que no ha habido error 
     * al finalizar el programa
     */
     return 0;
 }
 
 
