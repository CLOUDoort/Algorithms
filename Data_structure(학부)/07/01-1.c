#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

int maze[MAX_SIZE][MAX_SIZE];
int mark[MAX_SIZE][MAX_SIZE];
typedef struct {
    int vert;
    int horiz;
} offsets;
offsets move[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

typedef struct {
    int row;
    int col;
    int dir;
} element;
element stack[MAX_SIZE];
int top = -1;

void push(element item) {
    if(top >= MAX_SIZE-1) {
        printf("stack full\n");
        exit(1);
    }
    stack[++top] = item;
}

element pop() {
    if(top < 0) {
        printf("stack empty\n");
        exit(1);
    }
    return stack[top--];
}

void path(int exit_row, int exit_col);

int main() {
    FILE *fp = fopen("in1.txt", "r");
    if(fp == NULL) {
        printf("File read error\n");
        exit(1);
    }
    int row, col;
    fscanf(fp, "%d %d", &row, &col);
    for(int i = 0; i < row+2; i++) {
        for(int j = 0; j < col+2; j++) {
            maze[i][j] = 1;
            mark[i][j] = -1;
        }
    }
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            fscanf(fp, "%d", &maze[i][j]);
            mark[i][j] = 0;
        }
    }
    path(row, col);
    fclose(fp);
    return 0;
}

void path(int exit_row, int exit_col) {
    int i, row, col, nextRow, nextCol, dir;
    int found = FALSE;
    element position;
    mark[1][1] = 1; top = 0;
    stack[0].row = 1; stack[0].col = 1;
    stack[0].dir = 1;
    while(top > -1 && !found) {
        position = pop();
        row = position.row; col = position.col; dir = position.dir;
        while(dir < 8 && !found) {
            nextRow = row+move[dir].vert;
            nextCol = col+move[dir].horiz;
            if(nextRow == exit_row && nextCol == exit_col) found = TRUE;
            else if(!maze[nextRow][nextCol] && !mark[nextRow][nextCol]){
                mark[nextRow][nextCol] = 1;
                position.row = row; position.col = col; position.dir = ++dir;
                push(position);
                row = nextRow; col = nextCol; dir = 0;
            }
            else ++dir;
        }
    }
    if(found) {
        printf("The path is:\n");
        printf("row col\n");
        for(int i = 0; i <= top; i++) {
            printf("%2d%5d\n", stack[i].row, stack[i].col);
        }
        printf("%2d%5d\n", row, col);
        printf("%2d%5d\n", exit_row, exit_col);
    }
    else printf("The maze does not have a path\n");
}