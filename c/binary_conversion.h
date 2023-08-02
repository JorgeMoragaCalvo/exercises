#ifndef BINARY_CONVERSION_H
#define BINARY_CONVERSION_H

#include <stdbool.h>

enum MenuOption {
    BIN_TO_DEC = 1,
    DEC_TO_BIN,
    OCT_TO_DEC,
    DEC_TO_OCT,
    EXIT
};

void menu();
bool is_binary(char *str);
int binary_to_decimal(char str[]);
int digits(int num);
void binary_arr(int num, int *arr);


#endif // BINARY_CONVERSION_H
