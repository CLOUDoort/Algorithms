#include <stdio.h>
#include <stdlib.h>

int** make2dArray(int rows, int cols);
void init2dArray(int** arr, int row, int col);
void print2dArray(int** arr1, int** arr2, int row, int col);
void free2dArray(int** arr, int row);

int main() {
    int row, col;
    printf("Enter row, column size : ");
    scanf("%d %d", &row, &col);
    int** arr1 = make2dArray(row, col);
    int** arr2 = make2dArray(row, col);

    printf("Input A matrix : \n");
    init2dArray(arr1, row, col);
    printf("Input B matrix: \n");
    init2dArray(arr2, row, col);
    print2dArray(arr1, arr2, row, col);
    free2dArray(arr1, row); free2dArray(arr2, row);
    return 0;
}

void print2dArray(int** arr1, int** arr2, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", arr1[i][j] + arr2[i][j]);
        }
        printf("\n");
    }
}

void init2dArray(int **arr, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

int** make2dArray(int rows, int cols) {
    int**x = (int**)malloc(sizeof(*x)*rows);
    for(int i = 0; i < rows; i++){
        x[i] = (int*)malloc(cols*sizeof(**x));
    }
    return x;
}
void free2dArray(int **arr, int row) {
    for(int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);
}