#include "binary_conversion.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

bool is_binary(char str[]){
    int size = strlen(str);
    for(int i = 0; i < size; i++){
        if(str[i] != '0' && str[i] != '1') return false;
    }
    return true;
}
