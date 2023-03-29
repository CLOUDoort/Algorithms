/*
- 아이디어
    -파일에서 maze 정보 받아온다.
    -maze, mark 초기화해준다.
    -move 초기화해준다.
    -멤버 row, col, dir를 가지는 구조체 변수 element를 만들고 이를 요소로 가지는 stack 정적 배열 구현한다.
        - 초기화, push, pop, stackEmpty, stackFull 함수 구현한다.
    -길 찾는 path 함수 구현한다.
        -길 찾기 전 stack에 시작값을 넣어 초기화해준다.
        -stack에 element가 있으면서 not found 조건으로 while문 돌린다.
        -stack을 pop해주고 return값을 position에 넣는다.
        -현재 row, col, dir은 position의 row, col, dir이다.
        -현재 position 값 구했으면 이동할 수 있는 8가지 경우의 수를 돌린다.
            -dir이 8보다 낮으면서 not found인 조건으로 while문 돌린다.
            -경우의 수를 저장하는 nR, nC변수를 만든다.
            -목표지점과 같으면 found에 TRUE 대입
            -이동할 수 있거나, 방문한적이 없다면 
                - mark 1로 표시, position의 row, col, dir값 갱신
                -stack에 push
                -다시 row와 col에 nR, nC 넣어주고 dir은 0으로 초기화
*/
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

int maze[MAX_SIZE][MAX_SIZE];
int mark[MAX_SIZE][MAX_SIZE];
int EXIT_ROW;
int EXIT_COL;
typedef struct {
    int row;
    int col;
    int dir;
} Element;
Element stack[MAX_SIZE];
int top = -1;

void push(Element item) {
    if(top >= MAX_SIZE-1) {
        printf("Stack Memory Full!\n");
        return;
    }
    stack[++top] = item;
}

Element pop() {
    if(top == -1) {
        printf("No data\n");
        exit(-1);
    }
    return stack[top--];
}

void path() {
    int row, col, nR, nC, dir;
    int found = FALSE;
    Element position;
    mark[1][1] = 1; top = 0;
    stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;
    while(top > -1 && !found) {
        position = pop();
        row = position.row; col = position.col; dir = position.dir;
        while(dir < 8 && !found) {
            nR = row+move[dir].vert;
            nC = col+move[dir].horiz;
            if(nR == EXIT_ROW && nC == EXIT_COL) found = TRUE;
            else if(!maze[nR][nC] && !mark[nR][nC]) {
                mark[nR][nC] = 1;
                position.row = row; position.col = col; position.dir = ++dir;
                push(position);
                row = nR; col = nC; dir = 0;
            }
            else ++dir;
        }
    }
    if(found) {
        printf("The path is: \n");
        printf("row col\n");
        for(int i = 0; i <= top; i++) {
            printf("%2d%5d\n", stack[i].row, stack[i].col);
        }
        printf("%2d%5d\n", row, col);
        printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
    } else printf("The maze does not have a path\n");
}

int main() {
    int row, col;
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("Error\n");
        return 0;
    }
    fscanf(fp, "%d %d", &row, &col);
    EXIT_ROW = row; EXIT_COL = col;
    for(int i = 0; i < MAX_SIZE; i++) {
        for(int j = 0; j < MAX_SIZE; j++) {
            maze[i][j] = -1;
            mark[i][j] = -1;
        }
    }
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            fscanf(fp, "%d", &maze[i][j]);
            mark[i][j] = 0;
        }
    }
    for(int i = 0; i < 8; i++) {
        move[i].vert = dx[i];
        move[i].horiz = dy[i];
    }
    path();
    fclose(fp);
    return 0;
}