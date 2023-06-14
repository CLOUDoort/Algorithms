#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node {
    int data;
    nodePointer llink, rlink;
} node;

nodePointer createNode();
nodePointer insertNode(nodePointer *root, int data);
void printNode(nodePointer head);
void invertPrintNode(nodePointer head);

int main() {
    FILE*fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("file read error\n");
        exit(1);
    }
    nodePointer head = NULL, last = NULL;
    int value;
    while(fscanf(fp, "%d", &value) != EOF) {
        last = insertNode(&head, value);
    }
    printNode(head); invertPrintNode(last);
    fclose(fp);
    return 0;
}

void printNode(nodePointer head) {
    while(head) {
        printf("%d ", head->data);
        head = head->rlink;
    }
    printf("\n");
}
void invertPrintNode(nodePointer head) {
    while(head) {
        printf("%d ", head->data);
        head = head->llink;
    }
    printf("\n");
}

nodePointer insertNode(nodePointer *root, int data) {
    nodePointer cur = *root;
    nodePointer newNode = createNode();
    newNode->data = data;
    if(*root) {
        while(cur->rlink) {
            cur = cur->rlink;
        }
        newNode->llink = cur;
        cur->rlink = newNode;
    }
    else {
        *root = newNode;
    }
    return newNode;
}

nodePointer createNode() {
    nodePointer newNode = (nodePointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    newNode->llink = NULL; newNode->rlink = NULL;
    return newNode;
}