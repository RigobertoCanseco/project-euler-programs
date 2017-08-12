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