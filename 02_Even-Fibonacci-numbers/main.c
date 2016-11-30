//
// Created by regoeco on 29/11/16.
//
#include <stdio.h>
int main(void){
    int i, fib = 1, fib_ant = 1, fib_tmp;

    printf("%d, ", fib_ant);
    printf("%d, ", fib);
    for(i = 0; i<10; i++){
        fib_tmp = fib;
        fib = fib + fib_ant;
        fib_ant = fib_tmp;
        printf("%d, ", fib);
    }

    return 0;
}