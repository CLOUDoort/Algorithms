#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int row;
    int col;
    int value;
} Element;

void Compress(int SparseMatrix[][6], int row, int col, int cnt, Element CompressMatrix[]) {
    CompressMatrix[0].row = row;
    CompressMatrix[0].col = col;
    CompressMatrix[0].value = cnt;
    int idx = 1;
    for(int n = 0; n < row; n++) {
        for(int m = 0; m < col; m++) {
            if(SparseMatrix[n][m] != 0) {
                CompressMatrix[idx].row = n;
                CompressMatrix[idx].col = m;
                CompressMatrix[idx++].value = SparseMatrix[n][m];
            }
        }
    }
}

void smTranspose(Element a[], Element b[]) {
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;
    int currentb = 1;
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

void FastTranspose(Element a[], Element b[], int cnt) {
    int rowTerms[100], startingPos[100];
    b[0].row = a[0].col; b[0].col = a[0].row; b[0].value = a[0].value;
    if(a[0].value > 0) {
        for(int i = 0; i < a[0].col; i++) rowTerms[i] = 0;
        for(int i = 1; i <= a[0].value; i++) rowTerms[a[i].col]++;
        startingPos[0] = 1;
        for(int i = 1; i < a[0].col; i++) startingPos[i] = startingPos[i-1] + rowTerms[i-1];
        for(int i = 1; i <= a[0].value; i++) {
            int j = startingPos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    } 
}

int main() {
 int SparseMatrix[6][6] = {
        {15, 0, 0, 22, 0, -15},
        {0, 11, 3, 0, 0, 0},
        {0, 0, 0, -6, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {91, 0, 0, 0, 0, 0},
        {0, 0, 28, 0, 0, 0}
    };
    int cnt = 0;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if(SparseMatrix[i][j] != 0) cnt++;
        }
    }
    Element* CompressMatrix = (Element*)malloc(sizeof(*CompressMatrix)*cnt+1);
    Compress(SparseMatrix, 6, 6, cnt, CompressMatrix);

    for(int i = 0; i <= cnt; i++) {
        printf("row: %d col: %d value: %d\n", CompressMatrix[i].row, CompressMatrix[i].col, CompressMatrix[i].value);
    }
    Element* TransposeMatrix = (Element*)malloc(sizeof(*CompressMatrix)*cnt+1);
    smTranspose(CompressMatrix, TransposeMatrix);
    printf("\n\n");
    for(int i = 0; i <= cnt; i++) {
        printf("row: %d col: %d value: %d\n", TransposeMatrix[i].row, TransposeMatrix[i].col, TransposeMatrix[i].value);
    }
    Element* FastTransposeMatrix = (Element*)malloc(sizeof(*FastTransposeMatrix)*cnt+1);
    FastTranspose(CompressMatrix, FastTransposeMatrix, cnt);
    printf("\n\n");

    for(int i = 0; i <= cnt; i++) {
        printf("row: %d col: %d value: %d\n", FastTransposeMatrix[i].row, FastTransposeMatrix[i].col, FastTransposeMatrix[i].value);
    }

    free(FastTransposeMatrix);
    free(TransposeMatrix);
    free(CompressMatrix);
    return 0;
}