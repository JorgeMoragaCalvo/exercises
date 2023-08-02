#ifndef OCTAL_CONVERSION_H
#define OCTAL_CONVERSION_H

#include <stdbool.h>

typedef struct node_numbers {
    int value;
    struct node_numbers *next;
} node_numbers;


void printlist(node_numbers *head);
node_numbers *create_new_node(int num);
node_numbers *insert_at_beginning(node_numbers **head, node_numbers *node_insert);
void decimal_to_octal(int num);
int octal_to_decimal(int num);
bool is_octal(int num);

#endif // OCTAL_CONVERSION_H
