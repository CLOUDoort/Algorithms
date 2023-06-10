/*
- 아이디어
    - row, column 입력받는다.
    - 2차원 동적 배열을 생성하고 그 주소를 리턴하는 함수생성한다.
    - 값을 초기화해주는 함수 만든다.
    - 값 출력해주는 함수 만든다.
    - 메모리 해제 함수 만든다.
*/

#include <stdio.h>
#include <stdlib.h>

int** make2dArray(int row, int column) {
    int** newArray = (int**)malloc(sizeof(int*)*row);
    for(int i = 0; i < row; i++) {
        newArray[i] = (int*)malloc(sizeof(int)*column);
    }
    return newArray;
}

void init2dArray(int** arr, int row, int column) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void print2dArray(int** arr_A, int** arr_B, int row, int column) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            printf("%d ", arr_A[i][j]+arr_B[i][j]);
        }
        printf("\n");
    }
}

void free2dArray(int** arr, int row, int column) {
    for(int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int row, column;
    printf("Enter row, column size : ");
    scanf("%d %d", &row, &column);
    int** array_A = make2dArray(row, column);
    int** array_B = make2dArray(row, column);
    printf("Input A matrix : \n");
    init2dArray(array_A, row, column);
    printf("Input B matrix : \n");
    init2dArray(array_B, row, column);
    print2dArray(array_A, array_B, row, column);
    free2dArray(array_A, row, column);
    free2dArray(array_B, row, column);
    return 0;
}