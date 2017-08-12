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