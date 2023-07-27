#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
    Determine if a word or phrase is an isogram.
    An isogram (also known as a "non-pattern word") is a word or phrase without a repeating letter,
    however spaces and hyphens are allowed to appear multiple times.
*/

bool is_isogram(char *);

int main(){
    char *str = "six-year-old";

    if(is_isogram(str)) printf("La palabra o frase ES isogram\n");
    else printf("La palabra o frase NO es isogram\n");

    return 0;
}

bool is_isogram(char *str){
    int size = strlen(str);
    while(size > 0){
        for(int i = size - 1; i >= 0; i--){
            if((str[size] == str[i]) && (str[size] != '-' && str[size] != ' ')) return false;
        }
        size--;
    }
    return true;
}