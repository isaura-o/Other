#include <stdio.h>

int main(int argc, char** argv)
{
    int sel;
    
    printf("1. Opcion A\n");
    printf("2. Opcion B\n");
    printf("3. Opcion C\n");
    printf("0. Salir\n");
    
    do{
        printf("Opcion:");
        scanf("%d", &sel);
        
        switch(sel)
        {
            case 0:
                    break;
            case 1:
                    printf("Buena opcion la 1\n");
                    break;
            case 2:
                    printf("No me parece tan buena la"
                    " 2\n");
                    break;
            case 3: 
                    printf("La 3, definitivamente,"
                    "no me gusta\n");
                    break;
            default:
                    printf("Esta opcion no se ha"
                    "ofrecido...\n"
                    "Prube otra vez\n");
        }
    } while (sel!=0);
    return 0;
}
