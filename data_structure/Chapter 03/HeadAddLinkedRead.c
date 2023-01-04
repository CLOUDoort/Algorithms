#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node* next;
} Node;

int main(void) {
    Node *head = NULL;
    Node *tail = NULL;
    Node *cur = NULL;

    Node *newNode = NULL;
    int readData;

    // 데이터 입력과정
    while(1) {
        printf("데이터 입력 : ");
        scanf("%d", &readData);
        if(readData < 1) break;

        // 노드 추가과정
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else  {
            newNode->next = head;
            head = newNode;
        }
    }
    printf("\n");

    // 입력받은 데이터 출력과정
    printf("데이터 전체 출력! \n");
    if(head == NULL) printf("출력할 데이터가 없습니다! \n");
    else {
        cur = head;
        printf("%d ", cur->data);
        while(cur->next != NULL) {
            cur = cur->next;
            printf("%d ", cur->data);
        }
    }
    printf("\n\n");

    // 메모리 해제 과정 //
    if(head == NULL) return 0;
    else {
        Node* deleteNode = head;
        Node* deleteNextNode = head->next;
        printf("%d를 삭제합니다! \n", head->data);
        free(deleteNode);
        while(deleteNextNode != NULL) {
            deleteNode = deleteNextNode;
            deleteNextNode = deleteNextNode->next;
            printf("%d를 삭제합니다! \n", deleteNode->data);
            free(deleteNode);
        }
    }
    return 0;
}