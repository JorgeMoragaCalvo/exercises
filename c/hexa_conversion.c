#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const char BASE_HEX = 16;

typedef struct node {
    char value;
    struct node *next;
} hexa_node;

char hexa_digits(int);
int digits_hexa(char);

void print_hexa(hexa_node *);
hexa_node *create_new_node(char);
hexa_node *insert_at_beginning(hexa_node **, hexa_node *);
void decimal_to_hexa(int);
int hexa_to_decimal(char *);
bool is_hexa(char);


int main(){
    int num;
    char *c = malloc(sizeof(char) * 100);
    printf("Ingrese un numero hexadecimal: ");
    scanf(" %99[^\n]", c);
    int decimal = hexa_to_decimal(c);
    printf("Equivalente decimal de %s es: %d\n", c, decimal);
    
    printf("Ingrese un numero decimal: ");
    scanf("%d", &num);

    printf("Equivalente hexadecimal de %d es: ", num);
    decimal_to_hexa(num);
    free(c);

    return 0;
}


char hexa_digits(int num){
    char c;
    if(num < 10) c = num + '0';
    switch (num)
    {
    case 10:
        c = 'A';
        break;
    case 11:
        c = 'B';
        break;
    case 12:
        c = 'C';
        break;
    case 13:
        c = 'D';
        break;
    case 14:
        c = 'E';
        break;
    case 15:
        c = 'F';
        break;
    }
    return c;
}

hexa_node *create_new_node(char c){
    hexa_node *result = malloc(sizeof(hexa_node));
    result->value = c;
    result->next = NULL;
    return result;
}

hexa_node *insert_at_beginning(hexa_node **head, hexa_node *node_insert){
    node_insert->next = *head;
    *head = node_insert;
    return node_insert;
}

void print_hexa(hexa_node *head){
    hexa_node *temp = head;
    while(temp != NULL){
        printf("%c", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void decimal_to_hexa(int num){
    hexa_node *head = NULL;
    hexa_node *temp;
    int c;
    if(num < BASE_HEX){
        c = hexa_digits(num);
        temp = create_new_node(c);
        insert_at_beginning(&head, temp);
    }
    else{
        while(num >= BASE_HEX){
            int mod = num % BASE_HEX;
            c = hexa_digits(mod);
            temp = create_new_node(c);
            insert_at_beginning(&head, temp);
            num = num / BASE_HEX;
            if(num < BASE_HEX){
                c = hexa_digits(num);
                temp = create_new_node(c);
                insert_at_beginning(&head, temp);
            }
        }
    }
    print_hexa(head);
}

int digits_hexa(char c){
    int digit = c - '0';
    if(digit < 10) digit = digit;
    switch (c)
    {
    case 'A':
    case 'a':
        digit = 10;
        break;
    case 'B':
    case 'b':
        digit = 11;
        break;
    case 'C':
    case 'c':
        digit = 12;
        break;
    case 'D':
    case 'd':
        digit = 13;
        break;
    case 'E':
    case 'e':
        digit = 14;
        break;
    case 'F':
    case 'f':
        digit = 15;
    default:
        break;
    }
    return digit;
}

int hexa_to_decimal(char *c){
    int size = strlen(c);
    int sum = 0;
    for(int i = 0; i < size; i++){
        int num = digits_hexa(c[i]);
        sum += num * (int)pow(BASE_HEX, (size - (i + 1)));
    }
    return sum;
}