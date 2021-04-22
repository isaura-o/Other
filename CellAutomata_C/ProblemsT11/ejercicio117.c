#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int a, i;
    long int prod = 1;
    a = atoi(argv[1]);
    
    for (i = 1; i<=a; i++)
    {
        prod *= i;
    }
    printf("%ld\n",prod);
    return 0;    
}    
    /*  amb bucle while:
     *while( i<=a )
    {
    //    if (i == 0)
    //    {
    //        prod = 1;
    //    }else{
            prod *= i;
   
     //   }
        i++; 
    }
    
    printf("%ld\n",prod);
    return 0;
}*/
