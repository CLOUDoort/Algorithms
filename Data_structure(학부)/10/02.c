/*
- linkedList 구현하고 파일로부터 데이터 입력받는다.
- list 합치는 함수 구현한다.
- 출력 함수 구현
- 메모리 할당 해제 구현
- 파일 닫기
*/
#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x, y) ((x) < (y) ? -1 : ((x) == (y) ? 0 : 1))

typedef struct listNode* listPointer;
typedef struct listNode {
    int data;
    listPointer link;
}listNode;

listPointer createNode();
listPointer insertNode(listPointer *first, listPointer pre, int data);
listPointer unionList(listPointer a, listPointer b);
void printList(listPointer a);
void erase(listPointer *a);

int main() {
    FILE* fp1 = fopen("in3.txt", "r");
    if(fp1 == NULL) {
        printf("File error\n");
        exit(-1);
    }
    FILE* fp2 = fopen("in4.txt", "r");
    if(fp2 == NULL) {
        printf("File error\n");
        exit(-1);
    }

    listPointer a = NULL, b = NULL, preA = a, preB = b;
    int x = 0;
    while(fscanf(fp1, "%d", &x) != EOF) preA = insertNode(&a, preA, x);
    while(fscanf(fp2, "%d", &x) != EOF) preB = insertNode(&b, preB, x);
    listPointer c = unionList(a, b);
    printList(c);
    erase(&a); erase(&b); erase(&c);
    fclose(fp1); fclose(fp2);
    return 0;
}

listPointer unionList(listPointer a, listPointer b) {
    listPointer c, pre;
    c = NULL; pre = c;
    while(a && b) {
        switch(COMPARE(a->data, b->data)) {
            case -1: {
                pre = insertNode(&c, pre, a->data);
                a = a->link; break;
            }
            case 0: {
                pre = insertNode(&c, pre, a->data);
                a = a->link; b = b->link; break;
            }
            case 1: {
                pre = insertNode(&c, pre, b->data);
                b = b->link; break;
            }
        }
    }
    for(; a; a = a->link) pre = insertNode(&c, pre, a->data);
    for(; b; b = b->link) pre = insertNode(&c, pre, b->data);
    return c;
}

void printList(listPointer a) {
    while(a) {
        printf("%d ", a->data);
        a = a->link;
    }
}

void erase(listPointer *a) {
    listPointer delNode;
    while(*a) {
        delNode = *a;
        *a = (*a)->link;
        free(delNode);
    }
}

listPointer insertNode(listPointer *first, listPointer pre, int data) {
    listPointer newNode = createNode();
    newNode->data = data;
    if(*first) {
        newNode->link = pre->link;
        pre->link = newNode;
    }
    else {
        newNode->link = NULL;
        *first = newNode;
    }
    return newNode;
}

listPointer createNode() {
    listPointer newNode = (listPointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("Malloc Error\n");
        exit(-1);
    }
    return newNode;
}