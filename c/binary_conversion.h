#ifndef BINARY_CONVERSION_H
#define BINARY_CONVERSION_H

#include <stdbool.h>

typedef struct node_numbers {
    int value;
    struct node_numbers *next;
} node_numbers;

// Enumeración para las opciones del menú
enum MenuOption {
    BIN_TO_DEC = 1,
    DEC_TO_BIN,
    OCT_TO_DEC,
    DEC_TO_OCT,
    EXIT
};

// Funciones para el menú
void menu();
bool is_binary(char *str);
int binary_to_decimal(char str[]);
int digits(int num);
void binary_arr(int num, int *arr);
void printlist(node_numbers *head);
node_numbers *create_new_node(int num);
node_numbers *insert_at_beginning(node_numbers **head, node_numbers *node_insert);
void decimal_to_octal(int num);
int octal_to_decimal(int num);
bool is_octal(int num);

#endif // BINARY_CONVERSION_H
