//
// Created by regoeco on 4/12/16.
//
/*
    A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
    a^2 + b^2 = c^2

    For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

    There exists exactly one Pythagorean triplet for which a + b + c = 1000.
    Find the product abc.

    a² + b² - c² = 0
    a  +  b  + c = 1000







    a + 1 = b
    b + 1 = c
    a^² + (a+1)² + (a+2)² = 1000
    a² + a² + 2a + 1 + a² + 4a + 4 = 1000
    a(a + a + 2 + a + 4) + 5 = 1000
    a(3a + 6) + 5 = 1000
    a(3(a + 2) ) + 5 = 1000



    3a² + 6a + 5 = 1000
    2a¹ + a¹ + 2a + 4a + 5
    2a(a + 1) + a(a + 2) + 5

 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char ** argv)
{

    int a, b, c, i, j;
    for(i = 1; i<=100; i++){
        for (j = 1; j <= 100; j++) {
            a = i*i - j*j;
            b = 2*i*j;
            c = i*i + j*j;
            if(a >0 && b > 0 && c> 0  && a + b + c == 1000 )
                printf("a=%d, b=%d, c=%d, %0.0f, %d\n", a, b, c, pow(a, 2) * pow(b, 2) * pow(c,2), a * b * c  );
        }
    }
    return (EXIT_SUCCESS);
}
