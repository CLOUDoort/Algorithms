#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, column, i, j;
    int **arr;

    printf("행의 수는 ? : ");
    scanf("%d", &row);
    printf("열의 수는 ? : ");
    scanf("%d", &column);

    arr = (int**)malloc(sizeof(int*) * row * column);
    arr[0] = (int*)malloc(sizeof(int) * row * column);

    for(i = 1; i < row; i++) {
        arr[i] = arr[i-1] + column;
    }

    for(i = 0; i < row; i++) {
        for(j = 0; j < column; j++) {
            scanf("%d", &arr[i][j]);
            printf("%d행 %d열 :  %d \n", i, j, arr[i][j]);
        }
    }
    free(arr[0]);
    free(arr);
}