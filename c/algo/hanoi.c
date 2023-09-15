#include <stdio.h>

void hanoi(char [], char [], char [], int, int *);

int main (){
    int n;
    int step = 0;
    printf("Ingrese el numero de discos: ");
    scanf("%d", &n);
    hanoi("origen", "auxiliar", "destino", n, &step);

    return 0;
}

void hanoi(char ini[], char aux[], char end[], int n, int *step){
    if(n == 1){
        (*step)++;
        printf("Paso %d: mover disco de la torre %s a la torre %s.\n", *step, ini, end);
    } 
    else{
        hanoi(ini, end, aux, n - 1, step);
        (*step)++;
        printf("Paso %d: mover disco de la torre %s a la torre %s.\n", *step, ini, end);
        hanoi(aux, ini, end, n - 1, step);
    }
}