#include <stdio.h>
#include <stdlib.h>
#define MAX 500

/*
 * Page where get part of code, thanks
 * http://www.geeksforgeeks.org/factorial-large-number/
 */
/**
 *
 * @param n
 */
void factorial(int n);

int main(void){

    factorial(100);

    FILE *file = fopen("file.txt", "r");
    int c = 0, sum = 0;
    while((c = getc(file))!=EOF){
        sum += (c - '0');
    }
    fclose(file);
    printf("Sum:%d", sum);

    //93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
    return (EXIT_SUCCESS);
}

/**
 * 
 * @param x
 * @param res
 * @param res_size
 * @return
 */
int multiply(int x, int res[], int res_size)
{
    int carry = 0;  // Initialize carry
    int i;
    // One by one multiply n with individual digits of res[]
    for ( i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;  // Store last digit of 'prod' in res[]
        carry  = prod/10;    // Put rest in carry
    }

    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

/**
 * 
 * @param n 
 */
void factorial(int n)
{
    int tmp[MAX];
    char res[MAX];
    FILE *file = fopen("file.txt", "w");


    // Initialize result
    tmp[0] = 1;
    int res_size = 1;

    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    int x;
    for ( x=2; x<=n; x++)
        res_size = multiply(x, tmp, res_size);
    int i, j;
    for (i=res_size-1, j=0; i>=0; i--, j++)
        res[j] = tmp[i] + '0';

    fprintf(file, "%s", res);
    fclose(file);
}