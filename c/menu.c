#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "binary_conversion.h"
#include "octal_conversion.h"

#define MAX_BINARY_LENGTH 100

/*DRIVE CODE*/
int main(){
    printf("======================================\n");
    printf("Bienvenido/a a la calculadora binaria\n");
    printf("======================================\n");
    menu();
    printf("======================================\n");
    printf("Gracias por usar la calculadora binaria\n");
    printf("======================================\n");  
    return 0;
}

/*FUNCIONS*/

void menu(){
    enum MenuOption option;
    int num, size;
    char str[MAX_BINARY_LENGTH];
    do
    {
        printf("1. De Binario a Decimal\n");
        printf("2. De Decimal a Binario\n");
        printf("3. De Octal a Decimal\n");
        printf("4. De Decimal a Octal\n");
        printf("5. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &option);

        switch (option)
        {
        case BIN_TO_DEC:
            printf("Ingrese un numero binario: ");
            scanf(" %99[^\n]", str);
            getchar(); // Limpiar el buffer
            if(!is_binary(str)) printf("El numero ingresado no es binario...\n\n");
            else printf("El numero binario %s en decimal es: %d\n\n", str, binary_to_decimal(str));
            break;
        
        case DEC_TO_BIN:
            printf("Ingrese un numero: ");
            scanf("%d", &num);
            size = digits(num);
            int *binary_array = (int *)malloc(size * sizeof(int));
            if(binary_array == NULL){
                printf("Error de memoria.\n");
                exit(EXIT_FAILURE);
            }
            binary_arr(num, binary_array);
            printf("El numero %d en binario es: ", num);
            for(int i = size - 1; i >= 0; i--) printf("%d", binary_array[i]);
            printf("\n\n");
            break;
        case OCT_TO_DEC:
            printf("Ingrese un numero octal: ");
            scanf("%d", &num);
            if(is_octal(num)) printf("El numero %d en Octal es: %d\n", num, octal_to_decimal(num));
            else printf("el numero no es octal\n");
            printf("\n\n");
            break;            
        case DEC_TO_OCT:
            printf("Ingrese un numero decimal: ");
            scanf("%d", &num);
            printf("El numero %d en decimal es: ", num);
            decimal_to_octal(num);
            printf("\n\n");
            break;
        case EXIT:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion invalida...\n\n");
            break;
        }
    } while (option != 5);
}

