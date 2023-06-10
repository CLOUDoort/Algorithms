#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

typedef struct {
    int vert;
    int horiz;
} offsets;
offsets move[8];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1 ,-1 ,-1};

typedef struct {
    int row;
    int col;
    int dir;
} Element;
Element stack[MAX_SIZE];
int top = -1;

int maze[MAX_SIZE][MAX_SIZE];
int mark[MAX_SIZE][MAX_SIZE];

void push(Element item) {
    if(top >= MAX_SIZE-1) {
        printf("Full\n");
        return;
    }
    stack[++top] = item;
}
Element pop() {
    if(top == -1) {
        printf("No data\n");
        exit(1);
    }
    return stack[top--];
}

void path(FILE* fp2, int startX, int startY, int endX, int endY, int row_size, int col_size) {
    int row, col, nR, nC, dir;
    int found = FALSE; Element position;
    mark[startX][startY] = 1; top = 0;
    stack[0].row = startX; stack[0].col = startY; stack[0].dir = 0;
    while(top > -1 && !found) {
        position = pop();
        row = position.row; col = position.col; dir = position.dir;
        while(dir < 8 && !found) {
            nR = row + move[dir].vert;
            nC = col + move[dir].horiz;
            if(nR == endX && nC == endY) found = TRUE;
            else if(!maze[nR][nC] && !mark[nR][nC]) {
                mark[nR][nC] = 1;
                position.row = row; position.col = col; position.dir = ++dir;
                push(position);
                row = nR; col = nC; dir = 0;
            }
            else ++dir;
        }
    }
    for(int i = 1; i <= row_size; i++) {
        for(int j = 1; j <= col_size; j++) {
            int value = 0;
            for(int k = 0; k <= top; k++) {
                if(stack[k].row == i && stack[k].col == j) { 
                    fprintf(fp2, "%c ", 'x');
                    value = 1;
                    break;
                }
            }
            if(!value) {
                if(row == i && col == j) {
                    fprintf(fp2, "%c ", 'x');
                }
                else if(endX == i && endY == j) {
                    fprintf(fp2, "%c ", 'x');
                }
                else { 
                    fprintf(fp2, "%d ", maze[i][j]);
                }
            }
        }
        fprintf(fp2, "\n");
    }
}


int main() {
    int row, col;
    FILE* fp1 = fopen("in1.txt", "r");
    if(fp1 == NULL) {
        printf("Error\n");
        return 0;
    }
    FILE *fp2 = fopen("out.txt", "w");
    if(fp2 == NULL) {
        printf("Error\n");
        return 0;
    }
    fscanf(fp1, "%d %d", &row, &col);
    for(int i = 0; i < MAX_SIZE; i++) {
        for(int j = 0; j < MAX_SIZE; j++) {
            maze[i][j] = -1;
            mark[i][j] = -1;
        }
    }
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            fscanf(fp1, "%d", &maze[i][j]);
            mark[i][j] = 0;
        }
    }
    int startX, startY, endX, endY;
    scanf("%d %d %d %d", &startX, &startY, &endX, &endY);
    for(int i = 0; i < 8; i++) {
        move[i].vert = dx[i];
        move[i].horiz = dy[i];
    }
    path(fp2, startX, startY, endX, endY, row, col);
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}