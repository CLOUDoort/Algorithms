/*
- initNode 함수
    - 파일로부터 데이터 입력받아 리스트 형성한다.
    - insertNode 함수를 이용하여 입력받으려 했으나 오히려 더 복잡해질 것 같아 직접 입력받음.
- insertNode 함수
    - 매개변수로 listPointer head와 입력할 데이터를 입력한다.
    - 오름차순으로 데이터를 입력해야 한다.
    - head가 데이터보다 큰 경우와 아닌 경우, 또한 마지막에 데이터를 입력하는 경우를 구분해서 데이터를 입력해야 한다.
- searchNode 함수
    - head부터 데이터를 비교해서 데이터를 탐색한다.
    - 찾으면 따로 설정한 index를 반환하고 찾지 못하면 0을 반환한다.
- deleteNode 함수
    - head데이터를 삭제하는 경우와 아닌 경우, 또한 마지막 데이터를 삭제하는 경우를 구분해서 구현해야 한다.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
typedef struct listNode {
    listPointer llink;
    int data;
    listPointer rlink;
} listNode;

listPointer createNode();
void initNode(listPointer *head);
void insertNode(listPointer *head, int data);
void searchNode(listPointer head);
void deleteNode(listPointer *head);
void printNode(listPointer head);
void eraseNode(listPointer *head);

int main() {
    int a = 0;
    int insert_data = 0;
    listPointer head = NULL;
    while(1) {
        printf("작업 선택 (1.입력 2.추가 3.검색 4.삭제 5.종료) >> ");
        scanf("%d", &a);
        if(a == 5) break;
        if(a == 1) initNode(&head);
        else if(a == 2) {
            printf("데이터 입력 >> ");
            scanf("%d",&insert_data);
            insertNode(&head, insert_data);
        }
        else if(a == 3) searchNode(head);
        else if(a == 4) deleteNode(&head);
    }
    eraseNode(&head);
    return 0;
}

void deleteNode(listPointer *head) {
    int del_data = 0;
    listPointer delNode, cur = *head;
    printf("삭제 데이터 >> ");
    scanf("%d", &del_data);
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
            // 마지막 노드인 경우
            else {
                delNode = cur;
                cur->llink->rlink = NULL;
                free(delNode);
                printNode(*head);
                return;
            }
        }
        else cur = cur->rlink;
    }
    printf("invalid!\n"); return;
}

void searchNode(listPointer head) {
    int target = 0;
    int index = 1;
    listPointer cur = head;
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

void insertNode(listPointer *head, int data) {
    listPointer newNode = createNode();
    newNode->data = data;
    listPointer cur = *head, pre = *head;
    if((*head)->data > data) {
        newNode->rlink = *head;
        newNode->llink = NULL;
        (*head)->llink = newNode;
        *head = newNode;
        printNode(*head); return;
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
                pre->rlink = newNode;
                cur->llink = newNode;
                printNode(*head); return;
            }
        }
        // cur이 null일 경우, 즉 마지막에 삽입하는 경우
        newNode->llink = pre;
        pre->rlink = newNode;
        printNode(*head);
        return;
    }
}

void initNode(listPointer *head) {
    char FILE_NAME[10];
    printf("file 이름 입력 >> ");
    scanf("%s", FILE_NAME);
    
    FILE *fp = fopen(FILE_NAME, "r");
    if(fp == NULL) {
        printf("File read error\n");
        exit(1);
    }
    int a = 0;
    fscanf(fp, "%d", &a);
    // 헤드 노드 먼저 만듬
    listPointer headNode = createNode();
    headNode->data = a;
    headNode->rlink = NULL; headNode->llink = NULL; *head = headNode;

    // 헤드 노드 주소를 cur 변수에 넣고 데이터 입력받는다.
    // insert 함수를 이용하려했으나 너무 복잡해서 그냥 init함수는 이렇게 만들었음.
    listPointer cur = *head;
    while(fscanf(fp, "%d", &a) != EOF) {
        listPointer newNode = createNode();
        newNode->data = a; newNode->llink = cur; newNode->rlink = NULL;
        cur->rlink = newNode;
        cur = newNode;
    }
    printNode(*head);
    fclose(fp);
}

void eraseNode(listPointer *head) {
    listPointer delNode;
    while(*head) {
        delNode = *head;
        *head = (*head)->rlink;
        free(delNode);
    }
}

void printNode(listPointer head) {
    while(head) {
        printf("%d ", head->data);
        head = head->rlink;
    }
    printf("\n");
}

listPointer createNode() {
    listPointer newNode = (listPointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    return newNode;
}