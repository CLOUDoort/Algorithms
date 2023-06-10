/*
- 문제에 주어진대로 adjacency list를 구성한다.
- queue를 구현하고 bfs를 돌린다.
*/

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTEX 8

typedef struct node* nodePointer;
typedef struct node {
    int vertex;
    nodePointer link;
} node;

int queueList[MAX_VERTEX];
int visit[MAX_VERTEX];
int front, rear;
nodePointer adjLists[MAX_VERTEX];

void addq(int vertex);
int deleteq();
nodePointer createNode(int vertex);
void init();
void bfs(int i);

int main() {
    int n;
    scanf("%d", &n);
    init();
    bfs(n);
    return 0;
}

void bfs(int i) {
    nodePointer w;
    front = rear = -1;
    printf("%d ", i);
    visit[i] = TRUE;
    addq(i);
    while(front != rear) {
        i = deleteq();
        for(w = adjLists[i]->link; w; w = w->link) {
            if(!visit[w->vertex]) {
                printf("%d ", w->vertex);
                addq(w->vertex);
                visit[w->vertex] = TRUE;
            }
        }
    }
}

int deleteq() {
    if(front == rear) {
        printf("empty queue\n");
        exit(1);
    }
    front = (front+1)%MAX_VERTEX;
    return queueList[front];
}

void addq(int vertex) {
    rear = (rear+1)%MAX_VERTEX;
    if(front == rear) {
        printf("queue full\n");
        exit(1);
    }
    queueList[rear] = vertex;
}

void init() {
    for(int i = 0; i < 8; i++) {
        adjLists[i] = createNode(0);
    }
    adjLists[0]->link = createNode(1);
    adjLists[0]->link->link = createNode(2);

    adjLists[1]->link = createNode(0);
    adjLists[1]->link->link = createNode(3);
    adjLists[1]->link->link->link = createNode(4);

    adjLists[2]->link = createNode(0);
    adjLists[2]->link->link = createNode(5);
    adjLists[2]->link->link->link = createNode(6);

    adjLists[3]->link = createNode(1);
    adjLists[3]->link->link = createNode(7);

    adjLists[4]->link = createNode(1);
    adjLists[4]->link->link = createNode(7);

    adjLists[5]->link = createNode(2);
    adjLists[5]->link->link = createNode(7);

    adjLists[6]->link = createNode(2);
    adjLists[6]->link->link = createNode(7);

    adjLists[7]->link = createNode(3);
    adjLists[7]->link->link = createNode(4);
    adjLists[7]->link->link->link = createNode(5);
    adjLists[7]->link->link->link->link = createNode(6);
}

nodePointer createNode(int vertex) {
    nodePointer newNode = (nodePointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    newNode->link = NULL;
    newNode->vertex = vertex;
    return newNode;
}