#include <stdio.h>
#include <stdlib.h>
#define ZERO 48
#define SPACE 32
#define NEW_LINE 10
#define DIR_FILE "../13_Large-sum/file.txt"


// a_n --> a_n-1 --> a_n-2 --> ... --> a_1 --> a_0 --> NULL

typedef struct STACK_DATA stack_data;
typedef struct STACK stack;
struct File{
    FILE *f;
    const char * path_name;
};

struct STACK_DATA{
    char d;
    struct STACK_DATA *ant;
};

struct STACK{
    void (*insert)(char i, stack_data *s);
    void (*print_all)(stack_data *s);
    stack_data stackData;
};

void push( char i, stack_data *s) {
    size_t size = (size_t)sizeof(stack_data);
    stack_data *new = malloc(size);
    new->d = i;
    new->ant = s;
    s = new;
    printf("insert:%c\n", new->d);
}

void print_all(stack_data *s){
    stack_data *s_tmp;
    s_tmp = s;
    if(s_tmp != NULL){
        do{
            printf("%c-->", s_tmp->d);
            s_tmp = s_tmp->ant;
        }
        while( s_tmp != NULL);
    }
    printf("NULL");
}

int main(int argc, char ** argv) {

    int i, j, k, array[100][50], d[100], sum;

    struct File file;

    file.path_name = DIR_FILE;
    file.f = fopen(file.path_name, "r");

    //READ OF FILE
    for(i = 0; i<100; i++){
        for(j = 0; j <50; j++){
            array[i][j] = getc(file.f) - ZERO;
        }
        getc(file.f);//new line ignored
    }

    sum = 0;
    for(j = 49; j >= 0; j--){
        for(i = 0, d[j] = sum ; i<100; i++){
            d[j] += array[i][j];
        }
        if(0!=j){
            sum = d[j]/10;
            d[j] = d[j]%10;
        }
    }

    for(k = 0; k < 50; k++) {
        printf("%d", d[k]);
    }


    fclose(file.f);
    return (EXIT_SUCCESS);
}



/*
    stack digits;
    digits.insert = (void (*)(char, stack_data *)) push;
    digits.print_all = (void(*)(stack_data *))print_all;


    digits.stackData;
    digits.insert('A', &digits.stackData);
    digits.print_all(&digits.stackData);
 */