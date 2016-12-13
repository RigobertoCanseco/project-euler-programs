//
// Created by regoeco on 9/12/16.
//
/*
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <stdio.h>
#include <math.h>
int main(void){
    int i;
    long double  n = 0, c, max[2] = {0,0};
    for(i=2; i<1000000; i++){
        for(c = 1, n = i; n!=1; n = (fmod(n,2)==0)? n/2: 3*n+1, c++);
        if(c> max[1]){
            max[0] = i;
            max[1] = c;
        }
    }
    printf("%0.0Lf, %0.0Lf", max[0], max[1]);
    return 1;
}