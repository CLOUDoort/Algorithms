#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
typedef struct listNode {
    int data;
    listPointer link;
} listNode;

listPointer createNode();
void insertNode(listPointer *first, int data);
void printNode(listPointer first);
void freeNode(listPointer *first);

int main() {
    FILE *fp = fopen("in2.txt", "r");
    if(fp == NULL) {
        printf("File read error\n");
        exit(1);
    }
    listPointer first = NULL;
    int a;
    while(fscanf(fp, "%d", &a) != EOF) insertNode(&first, a);
    int x;
    while(1) {
        scanf("%d", &x);
        if(x == -1) break;
        insertNode(&first, x);
        printNode(first);
    }
    fclose(fp);
    freeNode(&first);
    return 0;
}

listPointer createNode() {
    listPointer newNode = (listPointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    return newNode;
} 

void insertNode(listPointer *first, int data) {
    listPointer pre, tempFirst = *first;
    listPointer newNode = createNode();
    newNode->data =data;

    if(*first) {
        if((*first)->data > data) {
            newNode->link = (*first)->link;
            *first = newNode;
        }
        while(tempFirst->data <= data) {
            pre = tempFirst;
            tempFirst = tempFirst->link;
        }
        newNode->link = pre->link;
        pre->link = newNode;
    }
    else {
        newNode->link = NULL;
        *first = newNode;
    }
}

void printNode(listPointer first) {
    while(first) {
        printf("%d ", first->data);
        first = first->link;
    }
}
void freeNode(listPointer *first) {
    listPointer delNode;
    while(*first) {
        delNode = *first;
        *first = (*first)->link;
        free(delNode);
    }
}