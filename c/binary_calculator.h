#ifndef BINARY_CALCULATOR_H
#define BINARY_CALCULATOR_H

#include <stdbool.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node node_numbers;

enum MenuOption {
    BIN_TO_DEC = 1,
    DEC_TO_BIN,
    OCT_TO_DEC,
    DEC_TO_OCT,
    EXIT
};


int binary_to_decimal(char []);
int digits(int);
void binary_arr(int, int *);
bool is_binary(char []);
void menu();
void printlist(node_numbers *);
node_numbers *create_new_node(int);
node_numbers *insert_at_beginning(node_numbers **, node_numbers *);
void decimal_to_octal(int);
int octal_to_decimal(int);
bool is_octal(int);

#endif // BINARY_CALCULATOR_H