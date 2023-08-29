#include <stdio.h>
#include <strings.h>
#include <string.h>

int bin_to_octal(char []);

int main(){
    char str[] = "10110001101011";
    //printf("%d", bin_to_octal(str));

    int size = strlen(str);
    int remainder = size % 3;
    if(remainder != 0){
        for(int k = 0; k < remainder; k++) printf("%c", str[k]);
        printf("\n");
        int i = remainder, j = 0;
        while(i < size){
            while(j < 3){
                printf("%c", str[i]);
                i++;
                j++;
            }
            j = 0;
            printf("\n");
        }
    }
    else{
        int i = 0, j = 0;
        while(i < size){
            while(j < 3){
                printf("%c", str[i]);
                i++;
                j++;
            }
            j = 0;
            printf("\n");
        }
    }
    return 0;
}


int bin_to_octal(char str[]){
    char *binary_values[] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    for(int i = 0; i < 8; i++){
        if(strcasecmp(str, binary_values[i]) == 0) return i;
    }
    return -1;
}

