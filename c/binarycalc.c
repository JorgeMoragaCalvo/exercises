#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "binary_calculator.h"

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
int binary_to_decimal(char str[]){
    int size = strlen(str);
    int sum = 0;
    for(int i = size - 1; i >= 0; i--) sum += (str[i] - '0') << (size - (i + 1));
    return sum;
}

int digits(int num){
    int count = 0, aux;
    while(num >= 2){
        aux = num % 2;
        count++;
        num = num / 2;
        if(num < 2) count++;
    }
    return count;
}

void binary_arr(int num, int *arr){
    int i = 0;
    while(num >= 2){
        arr[i] = num % 2;
        num = num / 2;
        i++;
    }
    arr[i] = num;
}

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

bool is_binary(char str[]){
    int size = strlen(str);
    for(int i = 0; i < size; i++){
        if(str[i] != '0' && str[i] != '1') return false;
    }
    return true;
}

void printlist(node_numbers *head){
    node_numbers *temp = head;
    while (temp != NULL){
        printf("%d", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

node_numbers *create_new_node(int num){
    node_numbers *result = malloc(sizeof(node_numbers));
    result->value = num;
    result->next = NULL;
    return result;
}

node_numbers *insert_at_beginning(node_numbers **head, node_numbers *node_insert){
    node_insert->next = *head;
    *head = node_insert;
    return node_insert;
}

void decimal_to_octal(int num){
    node_numbers *temp;
    node_numbers *head = NULL;
    while(num >= 8){
        int mod = num % 8;
        temp = create_new_node(mod);
        insert_at_beginning(&head, temp);
        num = num / 8;
        if(num < 8){
            temp = create_new_node(num);
            insert_at_beginning(&head, temp);
        }
    }
    printlist(head);
}

int octal_to_decimal(int num){
    int sum = 0;
    int base = 1; // Potencia de 8 correspondiente al dígito actual
    while (num > 0) {
        int digit = num % 10;
        sum += digit * base;
        num /= 10;
        base *= 8;
    }

    return sum;
}

bool is_octal(int num){
    while(num > 0){
        int digit = num % 10;
        if(digit >= 8) return false;
        num /= 10;
    }
    return true;
}