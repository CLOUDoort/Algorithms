#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef struct {
    int vert;
    int horiz;
} offsets;
offsets move[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

typedef struct {
    int row;
    int col
    int dir;
} element;
element stack[MAX_SIZE];
int top = -1;

int maze[MAX_SIZE][MAX_SIZE];
int mark[MAX_SIZE][MAX_SIZE];

void push(element item);
element pop();
void path(int exit_row, int exit_col);

int main() {
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("File read error\n");
        exit(1);
    }
    int row, col;
    fscanf(fp, "%d %d", &row, &col);
    int exit_col, exit_row;
    scanf("%d %d", exit_row, exit_col);
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
    path(exit_row, exit_col);
    fclose(fp);
    return 0;
}

void path(int exit_row, int exit_col) {
    int row, col, dir, nextRow, nextCol;
    int found = FALSE;
    element position;
    mark[1][1] = 1; top = 0;
    stack[0].row = 1; stack[0].col = 1;
}

void push(element item) {
    if(top >= MAX_SIZE-1) {
        printf("FULL\n");
        exit(1);
    }
    stack[++top] = item;
}
element pop() {
    if(top < 0) {
        printf("Empty\n");
        exit(1);
    }
    return stack[top--];
}