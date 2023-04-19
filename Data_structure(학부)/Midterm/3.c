// 2017116145 - 강준석
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
typedef struct listNode {
    char data;
    listPointer link;
} listNode;

listPointer createNode();
// 오름차순으로 데이터 삽입
void insertNode(listPointer *first, char data);
void deleteNode(listPointer *first, char target);
void printNode(listPointer first);
void freeNode(listPointer *first);

int main() {
    int a; char c;
    listPointer first = NULL;
    while(1) {
        printf("> 메뉴를 선택하세요 (1.삽입 2.삭제 3.종료): ");
        scanf(" %d", &a);
        if(a == 3) break;
        // 삽입
        else if(a == 1) {
            printf("문자를 입력하세요: ");
            scanf(" %c", &c);
            insertNode(&first, c);
            printNode(first);
        }
        // 삭제
        else if(a == 2) {
            printf("삭제할 문자를 입력하세요: ");
            scanf(" %c", &c);
            deleteNode(&first, c);
        }
    }
    freeNode(&first);
    return 0;
}

void freeNode(listPointer *first) {
    listPointer delNode;
    while(*first) {
        delNode = *first;
        *first = (*first)->link;
        free(delNode);
    }
}

void deleteNode(listPointer *first, char target) {
    listPointer temp = *first,  pre = NULL;
    // 데이터 탐색, 삭제
    if(*first) {
        while(temp) {
            if(temp->data == target) {
                if(temp == *first) {
                    *first = (*first)->link;
                    printNode(*first);
                    return;
                }
                else {
                    pre->link = temp->link;
                    printNode(*first);
                    return;
                }
            }
            else {
                pre = temp;
                temp = temp->link;
            }
        }
    }
    printf("잘못 입력하셨습니다. 다시 입력하세요.\n\n");
    return;
}

void insertNode(listPointer *first, char data) {
    listPointer cur = *first, pre;
    listPointer newNode = createNode();
    newNode->data = data;
    if(*first) {
        //  첫번째 노드가 더 큰 경우
        if((*first)->data > data) {
            newNode->link = *first;
            *first = newNode;
        }
        else {
            while(cur) {
                if(cur->data > data) {
                    newNode->link = pre->link;
                    pre->link = newNode;
                    return;
                }
                else {
                    pre = cur;
                    cur = cur->link;
                }
            }
            // 삽입 노드가 가장 큰 경우
            newNode->link = NULL;
            pre->link = newNode;
        }
    }
    else {
        newNode->link = NULL;
        *first = newNode;
    }
}

void printNode(listPointer first) {
    if(first) {
        while(first) {
            printf("%c ", first->data);
            first = first->link;
        }
        printf("null\n\n");
        return;
    }
    else printf("empty\n\n");
    return;
}

listPointer createNode() {
    listPointer newNode = (listPointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    return newNode;
}