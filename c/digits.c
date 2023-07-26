#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int digits(int);
int *arr_digits(int);
int armstrong(int);

int main(){
    int a = 371, n = 0, i = 2, p, b;
    
    //for(int i = digits(a) - 1; i >= 0; i--) printf("%d - ", arr_digits(a)[i]);

    //printf("\n%d\n", armstrong(a));
    while(i >= 0){
        p = (int) pow(10, i);
        b = a / p;
        printf("%d\n", b);
        a = a % p;
        //printf("%d\n", a);
        i--;
    }

    return 0;
}

int digits(int n){
    int count = 0;
    while(n != 0){
        n /= 10;
        count++;
    }
    return count;
}

int *arr_digits(int n){
    int count = digits(n);
    int *arr = (int *)malloc(count * sizeof(int));
    int i = 0;
    while(n != 0){
        arr[i++] = n % 10;
        n /= 10;
    }
    return arr;
}

int armstrong(int n){
    int sum = 0, b = digits(n);
    int *arr = arr_digits(n);
    for(int i = digits(n) - 1; i >= 0; i--) sum += pow(arr[i], digits(n));
    return sum == n ? 1 : 0;
}