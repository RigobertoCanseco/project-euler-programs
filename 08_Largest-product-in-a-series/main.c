#include <stdio.h>
#include <stdlib.h>
#define ZERO 48
#define DIR_FILE "file.txt"

struct File{
    FILE *f;
    const char * path_name;
};
struct File file;

int main(int argc, char ** argv)
{
    int max = 13;
    long double product = 1, product_tmp;
    int i, c = 1, digits[max];
    file.path_name = DIR_FILE;
    file.f = fopen(file.path_name, "r");

    for(i=0; i<max-1; i++){
        digits[i] = getc(file.f) - ZERO;
        if(digits[i] == 0){
            i = 0;
        }
    }
    while((c = getc(file.f)) != EOF){
        if(c == '0'){
            for(i=0; i<max-1; i++){
                digits[i] = getc(file.f) - ZERO;
                if(digits[i] == 0){
                    i = 0;
                }
            }
        } else{
            digits[max-1] = c - ZERO;
            for(i=0, product_tmp = 1; i<=max-1; product_tmp *= digits[i], i++);
            for(i=0; i<max-1; digits[i] = digits[i+1], i++);
            product = (product_tmp > product)?product_tmp: product;
        }
    }
    printf("Product:%0.0Lf\n", product);

    fclose(file.f);
    return (EXIT_SUCCESS);
}
