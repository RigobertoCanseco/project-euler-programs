//
// Created by regoeco on 1/12/16.
//
/*
    2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
    What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */
#include <stdio.h>
#include <math.h>
int main(void) {

    int i, k, j;
    i = 1;
    for (k=1; k<=25; k++)
        if( i%k > 0)
            for(j=1; j <=25; j++ )
                if((i*j) % k == 0){
                    i *= j;
                    break;
                }
    printf("Product:%d", i);



    /*
    int i, n, num[2]={0,0}, num_tmp[2], mult = 1, j, k;
    for(i = 2; i <=10; i++){
        num_tmp[0] = num_tmp[1] =  0;
        n = i;
        while(n != 1){
            if( n%2 == 0){
                n /= 2;
                num[0]++;
            }else if( n%3 == 0){
                n /= 3;
                num[1]++;
            }else{
                printf("%d,", i);
                break;
            }
        }
        if(n != i){
            for(j = 0; j < (num_tmp[0] - num[0]) ; j++){
                mult *= 2;
            }
            for(k = 0; k < (num_tmp[1] - num[1]) ; k++){
                mult *= 3;
            }
            num[0] = num_tmp[0] - num[0];
            num[1] = num_tmp[1] -  num[1];
        }
        mult*=n;

    }
    printf("Producto:%d", mult);
     */
}
/*
//1*2*5*7*8*9*11*13*17*19
//1*2*4*5*7*9
1*2*(2*2)*5*7*(3*3)
1*2*3*2*5*7*2*3
1=1
2=2
3=3
4=2*2
5=5
6=3*2
7=7
8=2*2*2
9=3*3
10=2*5

11=11
12=2*2*3
13=13
14=2*7
15=

 */
a2 + b2 + c2 + d2 = _X
        (a+b+c)_2 = y

x + y = z

