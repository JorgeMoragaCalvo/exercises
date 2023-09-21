#include <stdio.h>
#include <stdlib.h>


void plusOne(int *, int, int *);


int main(){
    int digits[] = {9};
    int size = sizeof(digits) / sizeof(digits[0]);
    int returnSize;

    plusOne(digits, size, &returnSize);

    printf("Result:");
    for (int i = 0; i < returnSize; i++) {
        printf(" %d", digits[i]);
    }

    printf("\nResult size: %d\n", returnSize);
    
    return 0;
}


void plusOne(int *digits, int digitsSize, int *returnDigits){
    int num = 0, count = 0;
    
    for(int i = 0; i < digitsSize; i++){
        num = num * 10 + digits[i];
    }
    
    num = num + 1;
    int temp = num;

    while(num > 0){
        num = num / 10;
        count++;
    }

    int n = 0;
    //digits = (int *)malloc(count * (sizeof(int)));

    for(int i = count - 1; i >= 0; i--){
        n = temp % 10;
        digits[i] = n;
        temp = temp / 10;
    }

    *returnDigits = count;
}