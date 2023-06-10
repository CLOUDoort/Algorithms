/*
- 트리 init 함수 생성
- queue, addQ, deleteQ 생성
- levelOrder 함수 생성
- eraseNode 함수 생성
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 7

typedef struct node* treePointer;
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
} node;

treePointer queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

treePointer createNode();
void initTree(treePointer *root);
void levelOrder(treePointer ptr);
void eraseNode(treePointer *root);
void addQ(treePointer item);
treePointer deleteQ();

int main() {
    treePointer root = createNode();
    initTree(&root);
    levelOrder(root);
    eraseNode(&root);
    return 0;
}

void levelOrder(treePointer ptr) {
    int front, rear;
    front = rear = 0;
    if(!ptr) return;
    addQ(ptr);
    for(;;) {
        ptr = deleteQ();
        if(ptr) {
            printf("%d ", ptr->data);
            if(ptr->leftChild) addQ(ptr->leftChild);
            if(ptr->rightChild) addQ(ptr->rightChild);
        }
        else break;
    }

}

void addQ(treePointer item) {
    rear = (rear+1)%MAX_QUEUE_SIZE;
    if(front == rear) {
        exit(1);
    }
    queue[rear] = item;
}

treePointer deleteQ() {
    if(front == rear) {
        exit(1);
    }
    front = (front+1)%MAX_QUEUE_SIZE;
    return queue[front];
}

void eraseNode(treePointer *root) {
    treePointer delNode;
    delNode = *root;
    if(*root) {
        eraseNode(&(delNode->leftChild));
        eraseNode(&(delNode->rightChild));
        free(delNode);
    }
}

void initTree(treePointer *root) {
    (*root)->data = 4;
    (*root)->leftChild = createNode(); (*root)->rightChild = createNode();
    treePointer rootLeft = (*root)->leftChild; treePointer rootRight = (*root)->rightChild;
    rootLeft->data = 3; rootRight->data = 6;
    
    rootLeft->leftChild = createNode(); rootLeft->rightChild = createNode();
    treePointer thirdLL = rootLeft->leftChild; treePointer thirdLR = rootLeft->rightChild;
    thirdLL->data = 2;
    thirdLR->data = 5;

    rootRight->rightChild = createNode();
    treePointer thirdRR = rootRight->rightChild;
    thirdRR->data = 8;
}

treePointer createNode() {
    treePointer newNode = (treePointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}