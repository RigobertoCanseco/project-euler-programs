//
// Created by regoeco on 30/11/16.
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143
//
#include <stdio.h>
#include <math.h>

int main(void){
    double d = 600851475143;

    int max = sqrt(d);
    while( max > 1){
        if(fmod(d,max) == 0)
            if(is_prime(max)) {
                printf("%d\n", max);
                break;
            }
        max--;
    }
    return 0;
}


int is_prime(int n){
    int i = 2;
    int max = sqrt(n);
    if (n ==1)
        return 0;
    while( i<=max ){
        if(fmod(n,i)==0)
            return 0;
        i++;
    }
    return 1;
}