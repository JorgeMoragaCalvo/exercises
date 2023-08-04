#include <stdio.h>
#include <limits.h>

/*PROTOTYPE*/
int kadane(int *, int);

/*DRIVE CODE*/
int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Suma maxima: %d\n", kadane(arr, size));

    return 0;
}

/*FUNCTION*/
int kadane(int *arr, int size){
    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    for(int i = 0; i < size; i++){
        max_ending_here += arr[i];
        if(max_so_far < max_ending_here) max_so_far = max_ending_here;
        if(max_ending_here < 0) max_ending_here = 0;
    }
    return max_so_far;
}