#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 11

typedef struct node* nodePointer;
typedef struct node {
    int data;
    nodePointer link;
} node;
nodePointer adjLists[MAX_VERTEX];
int board[MAX_VERTEX][MAX_VERTEX];

nodePointer createNode();

int main() {
    FILE* fp = fopen("in1.txt", "r");
    if(fp == NULL) {
        printf("file read error\n");
        exit(1);
    }
    int n = 0; fscanf(fp, "%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; i++) {
            fscanf(fp, "%d", &board[i][j]);
            board[j][i] = board[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        nodePointer pre = adjLists[i];
        adjLists[i] = createNode();
        for(int j = 1; j <= n; j++) {
            if(board[i][j] == 1) {
                nodePointer newNode = createNode();
                newNode->data = j;
                newNode->link = NULL;
                pre->link = newNode;
                pre = newNode;
            }
        }
    }

    fclose(fp);
    return 0;
}

nodePointer createNode() {
    nodePointer newNode = (nodePointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    return newNode;
}