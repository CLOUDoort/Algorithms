#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node {
    nodePointer llink, rlink;
    int data;
} node;

nodePointer createNode();
void initNode(nodePointer *head);
void insertNode(nodePointer *head, int data);
void searchNode(nodePointer head);
void deleteNode(nodePointer *head);
void printNode(nodePointer head);
void eraseNode(nodePointer *head);

int main() {
    int a = 0;
    nodePointer root = NULL;
    while(1) {
        printf("작업 선택 (1.입력 2.추가 3.검색 4.삭제 5.종료) >> ");
        scanf("%d", &a);
        if(a == 5) break;
        else if(a == 1) {
            initNode(&root);
            printNode(root);
        }
        else if(a == 2) {
            int data;
            printf("데이터 입력 >> "); scanf("%d", &data);
            insertNode(&root, data);
            printNode(root);
        }
        else if(a == 3) searchNode(root);
        else if(a == 4) deleteNode(&root);
    }
    eraseNode(&root);
    return 0;
}

void deleteNode(nodePointer *head) {
    int del_data = 0;
    nodePointer delNode, cur = *head;
    printf("삭제 데이터 >> " ); scanf("%d", &del_data);
    if((*head)->data == del_data) {
        delNode = *head;
        *head = (*head)->rlink;
        free(delNode); printNode(*head); return;
    }
    while(cur) {
        if(cur->data == del_data) {
            if(cur->rlink) {
                delNode = cur;
                cur->llink->rlink = cur->rlink;
                cur->rlink->llink = cur->llink;
                free(delNode); printNode(*head); return;
            }
            else {
                delNode = cur;
                cur->llink->rlink = NULL;
                free(delNode); printNode(*head); return;
            }
        }
        else cur = cur->rlink;
    }
    printf("invalid!\n"); return;
}

void searchNode(nodePointer head) {
    int target = 0;
    int index = 1;
    nodePointer cur = head;
    printf("검색 데이터 >> ");
    scanf("%d", &target);
    while(cur) {
        if(cur->data == target) {
            printf("%d\n", index);
            printNode(head);
            return;
        }
        else {
            cur = cur->rlink;
            index++;
        }
    }
    printf("%d\n", 0);
    printNode(head);
    return;
}

void insertNode(nodePointer *head, int data) {
    nodePointer newNode = createNode(), cur = *head, pre = *head;
    newNode->data = data;
    if(*head) {
        if((*head)->data >= data) {
            newNode->llink = NULL;
            newNode->rlink = *head;
            (*head)->llink = newNode;
            *head = newNode;
            return;
        }
        else {
            while(cur) {
                if(cur->data < data) {
                    pre = cur;
                    cur = cur->rlink;
                }
                else {
                    newNode->llink = pre;
                    newNode->rlink = cur;
                    pre->rlink->llink = newNode;
                    pre->rlink = newNode;
                    return;
                }
            }
            newNode->llink = pre;
            pre->rlink = newNode;
            return;
        }
    }
    else {
        newNode->llink = NULL;
        newNode->rlink = NULL;
        *head = newNode;
        return;
    }
}

void initNode(nodePointer *head) {
    char FILE_NAME[10]; int value = 0;
    printf("file 이름 입력 >> "); scanf("%s", FILE_NAME);
    FILE* fp = fopen(FILE_NAME, "r");
    if(fp == NULL) {
        printf("file read error\n");
        exit(1);
    }
    while(fscanf(fp, "%d", &value) != EOF) {
        insertNode(head, value);
    }
    fclose(fp);
}

void eraseNode(nodePointer *head) {
    nodePointer delNode;
    while(*head) {
        delNode = *head;
        *head = (*head)->rlink;
        free(delNode);
    }
}

void printNode(nodePointer head) {
    while(head) {
        printf("%d ", head->data);
        head = head->rlink;
    }
    printf("\n");
}

nodePointer createNode() {
    nodePointer newNode = (nodePointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    return newNode;
}