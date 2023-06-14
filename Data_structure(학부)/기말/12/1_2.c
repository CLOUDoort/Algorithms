#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node {
    int data;
    nodePointer llink, rlink;
} node;

nodePointer createNode();
void initList(nodePointer *root);
void insertNode(nodePointer *root, int data);
int searchNode(nodePointer root);
void deleteNode(nodePointer *root);
void printNode(nodePointer root);
void eraseNode(nodePointer *root);


int main() {
    int a;
    nodePointer root = NULL;
    while(1) {
        printf("작업 선택 (1. 입력 2.추가 3.검색 4.삭제 5.종료) >> ");
        scanf("%d", &a);
        if(a == 5) break;
        else if(a == 1) initList(&root);
        else if(a == 2) {
            printf("데이터 입력 >> ");
            int value; scanf("%d", &value);
            insertNode(&root, value);
        }
        else if(a == 3) searchNode(root);
        else if(a == 4) deleteNode(&root);
    }
    eraseNode(&root);
    return 0;
}

void initList(nodePointer *root) {
    char FILE_NAME[10]; int value = 0;
    printf("file 이름 입력 >> "); scanf("%s", FILE_NAME);
    FILE* fp = fopen(FILE_NAME, "r");
    if(fp == NULL) {
        printf("file read error\n");
        exit(1);
    }
    while(fscanf(fp, "%d", &value) != EOF) {
        insertNode(root, value);
    }
    fclose(fp);
}

void insertNode(nodePointer *root, int data) {
    nodePointer cur = *root, pre = *root;
    nodePointer newNode = createNode();
    newNode->data = data;
    if(*root) {
        if((*root)->data > data) {
            newNode->rlink = *root;
            (*root)->llink = newNode;
            *root = newNode;
        }
        else {
            while(cur) {
                if(cur->data < data) {
                    pre = cur;
                    cur = cur->rlink;
                }
                else {
                    newNode->llink = pre;
                    newNode->rlink = pre->rlink;
                    pre->rlink->llink = newNode;
                    pre->rlink = newNode;
                    printNode(*root);
                    return;
                }
            }
            newNode->llink = pre;
            pre->rlink = newNode;
        }
    }
    else {
        *root = newNode;
    }
    printNode(*root);
}

int searchNode(nodePointer root) {

}

void deleteNode(nodePointer *root) {

}

void eraseNode(nodePointer *root) {
    nodePointer delNode;
    while(*root) {
        delNode = *root;
        *root = (*root)->rlink;
        free(delNode);
    }
}

void printNode(nodePointer root) {
    while(root) {
        printf("%d ", root->data);
        root = root->rlink;
    }
    printf("\n");
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