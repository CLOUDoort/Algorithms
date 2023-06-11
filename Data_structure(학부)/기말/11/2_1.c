#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node {
    nodePointer llink;
    int data;
    nodePointer rlink;
} node;

nodePointer createNode();

nodePointer dinsert(nodePointer *node, int data);
void ddelete(nodePointer *node, int data);
void printNode(nodePointer node);
void eraseNode(nodePointer *node);
void invertPrintNode(nodePointer last);

int main() {
    FILE* fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("File read error\n");
        exit(1);
    }
    int value = 0;
    nodePointer root = NULL, last = NULL;
    while(fscanf(fp, "%d", &value) != EOF) {
        last = dinsert(&root, value);
    }

    printNode(root);
    invertPrintNode(last);
    eraseNode(&root);
    fclose(fp);
    return 0;
}

void eraseNode(nodePointer *node) {
    nodePointer delNode;
    while(*node) {
        delNode = *node;
        *node = (*node)->rlink;
        free(delNode);
    }
}

void invertPrintNode(nodePointer last) {
    while(last) {
        printf("%d ", last->data);
        last = last->llink;
    }
    printf("\n");
}

void printNode(nodePointer node) {
    while(node) {
        printf("%d ", node->data);
        node = node->rlink;
    }
    printf("\n");
}

void ddelete(nodePointer *node, int data) {

}

nodePointer dinsert(nodePointer *node, int data) {
    nodePointer cur = *node, pre = *node;
    nodePointer newNode = createNode();
    newNode->data = data;
    if(*node) {
        while(cur) {
            pre = cur;
            cur = cur->rlink;
        }
        newNode->llink = pre;
        newNode->rlink = pre->rlink;
        pre->rlink = newNode;
        
    }
    else {
        newNode->llink = NULL;
        newNode->rlink = NULL;
        *node = newNode;
    }
    return newNode;
}

nodePointer createNode() {
    nodePointer newNode = (nodePointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    return newNode;
}