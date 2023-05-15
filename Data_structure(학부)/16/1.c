/*
- 파일로부터 데이터를 받아 우선 Adjacency matrix를 만든다.
- 만든 matrix를 Adjacency list로 구현한다.
    - MAX_VERTEX의 크기를 가지는 nodePointer type의 adjList에 각 행의 헤더노드 포인터값을 넣는다.
    - 그리고 값이 존재한다면 헤드노드부터 시작하여 존재하는 값의 노드를 이어준다.
- 출력해준다.
- 메모리 해제해준다.
- 파일 스트림 닫는다.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 11

typedef struct node* nodePointer;
typedef struct node {
    int data;
    nodePointer link;
} node;
nodePointer adjLists[MAX_VERTEX];

int board[11][11];

nodePointer createNode();
void eraseNode(nodePointer *root);

int main() {
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("File read error\n");
        exit(1);
    }
    int n = 0;
    fscanf(fp, "%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            fscanf(fp, "%d", &board[i][j]);
            board[j][i] = board[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        adjLists[i] = createNode();
        nodePointer preNode = adjLists[i];
        for(int j = 1; j <= n; j++) {
            if(board[i][j] == 1) {
                nodePointer newNode = createNode();
                preNode->link = newNode;
                newNode->data = j;
                preNode = newNode;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        printf("Vertex %d: ", i);
        nodePointer temp = adjLists[i]->link;
        while(temp) {
            printf("%d ", temp->data);
            temp = temp->link;    
        }
        printf("\n");
    }
    for(int i = 1; i <= n; i++) {
        eraseNode(&adjLists[i]);
    }
    fclose(fp);
    return 0;
}

void eraseNode(nodePointer *root) {
    nodePointer delNode;
    while(*root) {
        delNode = *root;
        *root = (*root)->link;
        free(delNode);
    }
}

nodePointer createNode() {
    nodePointer newNode = (nodePointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("Malloc error\n");
        exit(1);
    }
    newNode->link = NULL;
    return newNode;
}