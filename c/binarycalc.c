#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int decimal(char []);
int amount_memory(int);
int* binary_arr(int);
bool is_binary(char []);
void menu();


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


int decimal(char str[]){
    int size = strlen(str);
    int *arr_decimal = (int *)malloc(size * sizeof(int));

    for(int i = 0; i < size; i++) arr_decimal[i] = str[i] - '0';
    int sum = 0;
    for(int i = size - 1; i >=0; i--) sum += arr_decimal[i] * (int)(pow(2, (size - (i + 1))));
    free(arr_decimal);

    return sum;
}

int amount_memory(int num){
    int count = 0, aux;
    while(num >= 2){
        aux = num % 2;
        count++;
        num = num / 2;
        if(num < 2) count++;
    }
    return count;
}

int* binary_arr(int num){
    int size = amount_memory(num);
    int *arr = (int *)malloc(size * sizeof(int));
    int i = 0;
    while(num >= 2){
        int mod = num % 2;
        arr[i] = mod;
        num = num / 2;
        i++;
        if(num < 2) arr[i] = num;
    }
    return arr;
}

void menu(){
    int option = 0;
    int num, size;
    char string[100];
    do
    {
        printf("1. De Binario a Decimal\n");
        printf("2. De Decimal a Binario\n");
        printf("3. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Ingrese un numero binario: ");
            scanf(" %99[^\n]", string);
            getchar(); // Limpiar el buffer
            if(!is_binary(string)) printf("El numero ingresado no es binario...\n\n");
            else printf("El numero binario %s en decimal es: %d\n\n", string, decimal(string));
            break;
        
        case 2:
            printf("Ingrese un numero: ");
            scanf("%d", &num);
            size = amount_memory(num);
            printf("El numero %d en binario es: ", num);
            for(int i = size - 1; i >= 0; i--) printf("%d", binary_arr(num)[i]);
            printf("\n\n");
            break;
        case 3:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion invalida...\n\n");
            break;
        }
    } while (option != 3);
}

bool is_binary(char str[]){
    int size = strlen(str);
    for(int i = 0; i < size; i++){
        if(str[i] != '0' && str[i] != '1') return false;
    }
    return true;
}