#include <stdio.h>
#include <stdlib.h>

int main(void){
    long double f = 1;
    int i;

    for(i = 1; i<=100; f*=i, i++);
    FILE *file = fopen("file", "w");
    fprintf(file,"%0.0Lf", f);
    fclose(file);
    file = fopen("file", "r");
    int c = 0, sum = 0;
    while((c = getc(file))!=EOF){
        sum += (c - '0');
    }
    fclose(file);
    printf("Result Factorial:%0.0Lf\n", f);
    printf("Sum:%d", sum);

    //93326215443944152638794559865674755492198008588591912695446327057475410739667358279337083640500903674397991236655991540282944112877360209308025154088724332544
    return (EXIT_SUCCESS);
}