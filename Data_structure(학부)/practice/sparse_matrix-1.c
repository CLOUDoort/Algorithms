#include <stdio.h>
#include <stdlib.h>

typedef struct _element {
    int row;
    int col;
    int value;
} Element;

void Compress(int SparseMatrix[][6], int row, int col, int cnt, Element CompMatrix[]) {
    CompMatrix[0].row = row;
    CompMatrix[0].col = col;
    CompMatrix[0].value = cnt;
    int idx = 1;
    for(int n = 0; n < row; n++) {
        for(int m = 0; m < col; m++) {
            if(SparseMatrix[n][m] != 0) {
                CompMatrix[idx].row = n;
                CompMatrix[idx].col = m;
                CompMatrix[idx++].value = SparseMatrix[n][m];
            }
        }
    }
}

void smTranspose(Element a[], Element b[]) {
    int currentb;
    b[0].col = a[0].row;
    b[0].row = a[0].col;
    b[0].value = a[0].value;

    // 총 원소 수가 0이 아닐 때
    if(a[0].value > 0) {
        currentb = 1;
        for(int i = 0; i < a[0].col; i++) {
            for(int j = 1; j <= a[0].value; j++) {
                if(a[j].col == i) {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb++].value = a[j].value;
                }
            }
        }
    }
}
void fast_transpose(Element a[], Element b[]) {
    int row_terms[100];
    int starting_pos[100];
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;
    if(a[0].value > 0) {
        for(int i = 0; i < b[0].col; i++) {
            row_terms[i] = 0;
        }
        for(int i = 1; i <= a[0].value; i++) {
            row_terms[a[i].col]++;
        }
        starting_pos[0] = 1;
        for(int i = 1; i < a[0].col; i++) {
            starting_pos[i] = starting_pos[i-1]+row_terms[i-1];
        }
    }
}

int main() {
    int SparseMatrix[6][6] = {
        {15, 0, 0, 22, 0, -15},
        {0, 11, 3, 0, 0, 0},
        {0, 0, 0, -6, 0, 0},
        {91, 0, 0, 0, 0, 0},
        {0, 0, 28, 0, 0, 0}
    };
    int cnt = 0;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if(SparseMatrix[i][j] != 0) cnt++;
        }
    }
    Element* CompMatrix = (Element*)malloc(sizeof(Element)*cnt+1);
    Compress(SparseMatrix, 6, 6, cnt, CompMatrix);
    for(int i = 0; i < cnt+1; i++) {
        printf("row: %d col: %d value: %d\n", CompMatrix[i].row, CompMatrix[i].col, CompMatrix[i].value);
    }
    Element* TransposeMatrix = (Element*)malloc(sizeof(Element)* cnt+1);
    smTranspose(CompMatrix, TransposeMatrix);
    printf("\n-------------------\n");
    for(int i = 0; i < cnt+1; i++) {
        printf("row: %d col : %d value: %d\n", TransposeMatrix[i].row, TransposeMatrix[i].col, TransposeMatrix[i].value);
    }
    free(CompMatrix);
    free(TransposeMatrix);
    return 0;
}