#include <stdio.h>
#include <string.h>

int is_isogram(char *);

int main(){
    char *str = "main-to-us";
    if(str[4] == "-") printf("Es igual\n");
    else printf("No es igual\n");

    printf("Largo: %d\n", strlen(str));
    //printf("%d\n", is_isogram(str));
    
    //if(is_isogram(str) == 1) printf("Is isogram\n");
    //else printf("Not isogram\n");
    printf("Resultado: %d\n", is_isogram(str));

    return 0;
}

int is_isogram(char *str){
    int size = strlen(str);
    int flag = 1;
    char a = "-", b = " ";
    while(size > 0){
        for(int i = size - 1; i >= 0; i--){
            if(str[size] == str[i]) flag = 0;
        }
        size--;
    }

    return flag;
}