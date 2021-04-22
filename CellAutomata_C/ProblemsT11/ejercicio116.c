#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    float a, b, c;
    
    a = atof(argv[1]);
    b= atof(argv[2]);
    c = a - b;
    if ( c>0 ){
        c = c;
    }else{
        c = -c;
    //    c = a - b;
    }
     
     printf("|%g-%g| = %g\n", a, b, c);
     
     return 0;   
}
