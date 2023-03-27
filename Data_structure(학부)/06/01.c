/*
- 아이디어
    - row, col, value를 나타내는 구조체 만든다.
    - 구조체 배열 A 선언하고, a.txt로부터 값을 입력받는다.
    - fastTranspose 함수 생성하고 transpose한 구조체 배열 B를 만든다.
    - B를 파일출력하는 함수 생성한다.
    - A와 B를 출력하는 함수 생성한다.
*/
#include <stdio.h>

typedef struct _element {
    int row;
    int col;
    int value;
} Element;

void fastTranspose(Element A[], Element B[]) {
    int i, j, row_terms[10], starting_pos[10], numCols = A[0].col, numTerms = A[0].value;
    B[0].row = numCols;
    B[0].col = A[0].row;
    B[0].value = numTerms;

    if(numTerms > 0) {
        for(i = 0; i < numCols; i++) row_terms[i] = 0;
        for(i = 1; i <= numTerms; i++) row_terms[A[i].col]++;
        starting_pos[0] = 1;
        for(i = 1; i < numCols; i++) starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
        for(i = 1; i <= numTerms; i++) {
            j = starting_pos[A[i].col]++;
            B[j].row = A[i].col;
            B[j].col = A[i].row;
            B[j].value = A[i].value;
        }
    }
}

void printMatrix(Element A[], char c) {
    printf("%c\n", c);
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            int flag = 0;
            printf("  ");
            for(int k = 1; k <= A[0].value; k++) {
                if(A[k].row == i && A[k].col == j) {
                    printf("%3d ", A[k].value);
                    flag = 1;
                    break;
                }
            }
            int zero_number = 0;
            if(!flag) printf("%3d ", zero_number);
        }
        printf("\n");
    }
}

void filePrintMatrix(FILE* fp, Element A[]) {
    for(int i = 0; i < 9; i++) {
        fprintf(fp, "%d %d %d\n", A[i].row, A[i].col, A[i].value);
    }
}

int main() {
    Element A[20], B[20];
    FILE *fp1 = fopen("a.txt", "r");
    if(fp1 == NULL) {
        printf("Error\n");
        return 0;
    }
    FILE *fp2 = fopen("b.txt", "w");
    if(fp2 == NULL) {
        printf("Error\n");
        return 0;
    }

    for(int i = 0; i < 9; i++) fscanf(fp1, "%d %d %d", &A[i].row, &A[i].col, &A[i].value);
    fastTranspose(A, B);
    filePrintMatrix(fp2, B);

    printMatrix(A, 'A');
    printMatrix(B, 'B');

    fclose(fp1);
    fclose(fp2);
    return 0;
}