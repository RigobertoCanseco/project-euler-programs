//
// Created by regoeco on 12/12/16.
//
/*
 *
    2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

    What is the sum of the digits of the number 21000?

 */
#include <stdio.h>
#include <math.h>

#define ZERO 48
#define DIR_FILE "../16_Power-digit-sum/file.txt"
struct File{
    FILE *f;
    const char * path_name;
};

int main(void){
    write(pow(2, 1000));
    printf("Sum:%d\n", sum());
    return 1;
}

void write(double num){
    struct File file;
    file.path_name = DIR_FILE;
    file.f = fopen(file.path_name, "w");
    fprintf(file.f, "%0.0f", num);
    fclose(file.f);
}

int sum(){
    struct File file;
    file.path_name = DIR_FILE;
    file.f = fopen(file.path_name, "r");
    int c, sum = 0;
    while((c=getc(file.f))!=EOF)
        sum += (c - ZERO);

    fclose(file.f);
    return sum;
}