#include <stdio.h>
#include <stdlib.h>
#define ZERO 48
#define SPACE 32
#define NEW_LINE 10
#define DIR_FILE "../11_Largest-product-in-a-grid/file.txt"

struct File{
    FILE *f;
    const char * path_name;
};
int array[20][20];

int main(int argc, char ** argv)
{
    int i, j, k, m, mult_max = 0;
    struct File file;
    int pos[4][2];

    file.path_name = DIR_FILE;
    file.f = fopen(file.path_name, "r");

    //READ OF FILE
    for(i = 0; i<20; i++){
        for(j = 0; j <20; j++){
            array[i][j] = (getc(file.f) - ZERO)*10 + getc(file.f) - ZERO;
            getc(file.f);
        }
    }
    //right
    for(j = 0; j<20; j++) {
        m = 1;
        for (i = 0; i < 20 - 3; m = 1, i++) {
            m *= array[j][i] * array[j][i+1] * array[j][i+2] * array[j][i+3];
            if(m>mult_max){
                for(k =0; k<4; k++){
                    mult_max = m;
                    pos[k][0] = j;
                    pos[k][1] = i + k;
                }
            }

            //printf("%d*%d*%d*%d=%d\n",array[j][i], array[j][i+1], array[j][i+2], array[j][i+3], m);
        }
    }
    //down
    for(j = 0; j<20; j++) {
        m = 1;
        for (i = 0; i < 20 - 3; m = 1, i++) {
            m *= array[i][j] * array[i+1][j] * array[i+2][j] * array[i+3][j];
            if(m>mult_max){
                for(k =0; k<4; k++){
                    mult_max = m;
                    pos[k][0] = i + k;
                    pos[k][1] = j;
                }
            }
            //printf("%d*%d*%d*%d=%d\n",array[i][j], array[i+1][j], array[i+2][j], array[i+3][j], m);
        }
    }
    //diagonal-rigth-down
    for(j = 0; j<20 -3; j++) {
        m = 1;
        for (i = 0; i < 20 - 3; m = 1, i++) {
            m *= array[j][i] * array[j+1][i+1] * array[j+2][i+2] * array[j+3][i+3];
            if(m>mult_max){
                for(k = 0; k<4; k++){
                    mult_max = m;
                    pos[k][0] = i + k;
                    pos[k][1] = j + k;
                }
            }
            //printf("%d*%d*%d*%d=%d\n",array[j][i], array[j+1][i+1], array[j+2][i+2], array[j+3][i+3], m);
        }
    }
    //diagonal-left.down
    for(j = 0; j<20 -3; j++) {
        m = 1;
        for (i = 19; i >= 3; m = 1, i--) {
            m *= array[j][i] * array[j+1][i-1] * array[j+2][i-2] * array[j+3][i-3];
            if(m>mult_max){
                for(k = 0; k<4; k++){
                    mult_max = m;
                    pos[k][0] = i + k;
                    pos[k][1] = j + k;
                }
            }
            //printf("%d*%d*%d*%d=%d\n",array[j][i], array[j+1][i-1], array[j+2][i-2], array[j+3][i-3], m);
        }
    }


    printf("max:%d\n", mult_max);
    for(k=0; k<4; k++){
        printf("[%d,%d] = %d\n",pos[k][0], pos[k][1], array[pos[k][0]][pos[k][1]]);
    }

    fclose(file.f);
    return (EXIT_SUCCESS);
}

