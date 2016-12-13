//
// Created by regoeco on 4/12/16.
//
/*
    The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
    Find the sum of all the primes below two million.
 */
#include <stdio.h>
#include <math.h>

int is_prime(int n){
    register int i = 2;
    int max = (int) sqrt(n);
    if (n ==1)
        return 0;
    while( i<=max ){
        if(fmod(n,i)==0)
            return 0;
        i++;
    }
    return 1;
}
int main(void){

    register long double  sum;
    register int i;
    for(i = 0, sum = 0; i< 2000000; is_prime(i)?sum+=i:0, i++);
    printf("%0.0Lf", sum);
    return 1;
}
//7472966967499 one milion
//