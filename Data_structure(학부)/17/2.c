/*
- 문제에 주어진 데이터로 adjacency list 구성하고 dfs 돌린다.
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

int visit[MAX_VERTEX];
nodePointer adjLists[MAX_VERTEX];

nodePointer createNode(int vertex);
void init();
void dfs(int i);

int main() {
    int n;
    scanf("%d", &n);
    init();
    printf("dfs(%d) : ", n);
    dfs(n);
    return 0;
}

void dfs(int i) {
    nodePointer w;
    visit[i] = TRUE;
    printf("%d ", i);
    for(w = adjLists[i]->link; w; w = w->link) {
        if(!visit[w->vertex]) {
            dfs(w->vertex);
        }
    }
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