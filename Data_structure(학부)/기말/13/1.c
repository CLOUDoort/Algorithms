/*
- 트리 init 함수 생성
- preorder 함수 생성
- eraseNode 함수 생성
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
} node;

treePointer createNode();
void initTree(treePointer *root);
void preorder(treePointer root);
void eraseNode(treePointer *root);

int main() {
    treePointer root = createNode();
    initTree(&root);
    preorder(root);
    eraseNode(&root);
    return 0;
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

void preorder(treePointer root) {
    if(root) {
        printf("%d ", root->data);
        preorder(root->leftChild);
        preorder(root->rightChild);
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