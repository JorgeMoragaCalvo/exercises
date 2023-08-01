#include "octal_conversion.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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