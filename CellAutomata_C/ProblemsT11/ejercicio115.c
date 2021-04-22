#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int a, b, c;
    
    a = atoi(argv[1]);
    b=atoi(argv[2]);
    //c= a+b;
    c = a/b;
    
    //printf("%d+%d=%d\n", a, b, c);
    printf("%d/%d=%d\n", a, b, c); // mai donara el valor correcte --> nomes dona enters!!
    
    return 0;
}
