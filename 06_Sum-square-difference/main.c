//
// Created by regoeco on 3/12/16.
//
/*
    The sum of the squares of the first ten natural numbers is,
    12 + 22 + ... + 102 = 385

    The square of the sum of the first ten natural numbers is,
    (1 + 2 + ... + 10)2 = 552 = 3025

    Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

    Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#include <stdio.h>
#include <math.h>
int main(void){

    int n = 100;
    int s1 = pow(n*(n + 1)/2, 2);
    int s2 = n*(n + 1)*(2*n + 1)/6;
    int r = s1 - s2;
    printf("Result:%d", r);
    return 1;
}