#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
} person;

unsigned int hash(char *name){
    return 5;
}


int main(){
    printf("Jacob => %u\n", hash("Jacob"));
    printf("Denisse => %u\n", hash("Denisse"));
    printf("Sara => %u\n", hash("Sara"));
    
    return 0;
}