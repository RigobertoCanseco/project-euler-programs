//
// Created by regoeco on 30/11/16.
//

/*
    A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
    Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <stdio.h>
#include <math.h>
int main(void) {
    printf("Palindrome:%d", max_palindrome(4));
    return 0;
}
int max_palindrome(int digit){
    int max = pow(10, digit) - 1;
    int i, j, mult, palindrome = 0;
    for(i = max; i>0; i--){
        for(j = max; j >0; j--){
            mult = i*j;
            if(is_palindrome(mult) && mult>palindrome)
                palindrome = mult;
        }
    }
    return palindrome;
}

int is_palindrome(int num){
    int i ,div, cont = 0;
    //number of digits
    for( i = 1, div = 1; div != 0; i*= 10,div = num/i, cont++);

    int p = (int)pow(10, cont-1), n, m, j = 10, c, is_palidromic = 1;
    for(c=cont/2; c>0; j*=10, p/=10, c--){
        //last digit
        n = (num % j) / (j / 10);
        //first digit
        m = num / p;
        if( n != m ){
            is_palidromic = 0;
            break;
        }
        //Reducing the number
        num -= m*p;
    }

    return is_palidromic;
}