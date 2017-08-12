#include <stdio.h>
#include <math.h>
int main(void){
    int fib = 1, fib_ant = 1, fib_tmp = 0;
    int max = 4000000, sum = 0;

    //printf("%0.0f\n", fib_ant);
    //printf("%0.0f\n", fib);
    while(fib < max){
        printf("%d\n", fib);
        if(fib%2 == 0)
            sum+=fib;
        fib_tmp = fib;
        fib += fib_ant;
        fib_ant = fib_tmp;
    }

    printf("Sum:%d\n", sum);
    return 0;
}