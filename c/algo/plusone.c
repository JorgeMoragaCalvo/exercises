#include <stdio.h>
#include <stdlib.h>


int *plusOne(int *, int, int *);


int main(){
    int digits[] = {9,9,9};
    int size = sizeof(digits) / sizeof(digits[0]);
    int returnSize;

    int *result = plusOne(digits, size, &returnSize);

    printf("Result:");
    for (int i = 0; i < returnSize; i++) {
        printf(" %d", result[i]);
    }

    printf("\nResult size: %d\n", returnSize);
    free(result);
    
    return 0;
}


int *plusOne(int *digits, int digitsSize, int *returnDigits){
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
    int *arr = (int *)malloc(count * (sizeof(int)));

    for(int i = count - 1; i >= 0; i--){
        n = temp % 10;
        arr[i] = n;
        temp = temp / 10;
    }

    *returnDigits = count;

    return arr;
}