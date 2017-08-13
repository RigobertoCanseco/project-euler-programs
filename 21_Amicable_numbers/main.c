#include <stdio.h>
#include <stdlib.h>

/**
 *
 * @param number
 * @return
 */
int *divisors(int number);

/**
 *
 * @param max
 * @return
 */
void amicable_numbers(int max);

int main(void){
    printf("Amicables numbers\n");

    amicable_numbers(1000);
    return (EXIT_SUCCESS);
}

/**
 *
 * @param max
 * @return
 */
void amicable_numbers(int max){
    int i, j, sum;
    int **list = calloc(sizeof(int), (size_t)max);
    int num[max][1];
    for(i = 1; i<=max; i++){
        list[i-1] = divisors(i);
        j = 0;
        printf("%d: ", i);
        sum = 0;
        while( list[i-1][j] !=  NULL){
            sum +=  list[i-1][j];
            printf("%d ", list[i-1][j++]);
        }
        printf(", %d \n", sum);
        num[i-1][0] = sum;
    }

    for(i = 0; i< max; i++){
        if(num[i][0]<1000 && num[i][0]!= 1 && (i+1) == num[0][num[i][0]-1] && num[i][0] != num[0][num[i][0]-1] &&
                num[i][0] == num[0][num[0][num[i][0]-1]-1]){
            printf(" %d , %d\n", i+1, num[i][0]);
        }
    }
}

/**
 *
 * @param number
 * @return
 */
int *divisors(int number){
    int i, j = 0;
    int one = 1;
    if(number == 1){
        int *d = malloc(sizeof(int));
        *d = one;
        return d;
    }

    int *divisors = calloc(sizeof(int), (size_t)abs(number/2));
    divisors[j++] = 1;
    for(i =2; i<number; i++){
        if(number%i == 0)
            divisors[j++] = i;
    }

    return divisors;
}

