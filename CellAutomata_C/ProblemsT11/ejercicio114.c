#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    
    printf("%f+%f=%f\n", atof(argv[1]), atof(argv[2]), atof(argv[1])+atof(argv[2]));
    
    return 0;
}
