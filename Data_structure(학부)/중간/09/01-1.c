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
    FILE *fp = fopen("in1.txt", "r");
    if(fp == NULL) {
        printf("File read error\n");
        exit(1);
    }
    listPointer first = NULL;
    int a = 0;
    while(fscanf(fp, "%d", &a) != EOF) {
        insertNode(&first, a);
    }
    printNode(first);
    freeNode(&first);
    fclose(fp);
    return 0;
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

void insertNode(listPointer *first ,int data) {
    listPointer x = NULL, tempFirst = *first;
    listPointer newNode = createNode();
    newNode->data = data;

    if(*first) {
        while(tempFirst) {
            x = tempFirst;
            tempFirst = tempFirst->link;
        }
        newNode->link = x->link;
        x->link = newNode;
    }
    else {
        newNode->link = NULL;
        *first = newNode;
    }
}

listPointer createNode() {
    listPointer newNode = (listPointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    return newNode;
}