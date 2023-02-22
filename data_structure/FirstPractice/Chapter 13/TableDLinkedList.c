#include <stdio.h>
#include <stdlib.h>
#include "TableDLinkedList.h"

void ListInit(List *plist) {
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}
// 정렬 기준이 마련되지 않았을 때 헤드에 노드를 추가하는 함수
// 현재 포인터 변수 head는 NULL이 아닌 dummy node를 가리키고 있다는 사실을 잊으면 안된다.
void FInsert(List *plist, LData data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head->next;
    plist->head->next = newNode;
    plist->numOfData++;
}
void SInsert(List *plist, LData data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node *pred = plist->head; // pred는 더미 노드를 가리킨다.
    newNode->data = data;

    // 새 노드가 들어갈 위치를 찾기 위한 반복문
    // pred->next는 첫 번째 노드를 의미
    while(pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
        pred = pred->next;
    }
    newNode->next = pred->next;
    pred->next = newNode;

    plist->numOfData++;
}

// 노드의 추가는 리스트의 멤버 comp에 무엇이 저장되어 이쓰냐에 따라서 FInsert 또는 SInsert 함수를 통해 진행된다.
// 하지만 이 두 함수 모두 헤더파일에 정의된 함수가 아니기 때문에 사용자가 직접 호출할 수 없고 리스트 내부적으로 호출이 되는 함수이다. => LInsert 함수를 통해 내부적으로 조건문에 따라 호출
void LInsert(List *plist, LData data) {
    // 정렬 기준이 마련되지 않았다면 헤드에 노드 추가
    if(plist->comp == NULL) FInsert(plist, data);
    // 정렬 기준이 마련되었다면, 정렬기준에 근거하여 노드를 추가
    else SInsert(plist, data);
}


int LFirst(List *plist, LData *pdata) {
    if(plist->head->next == NULL) return FALSE;
    plist->before = plist->head; // before은 dummy data를 가리키게 한다.
    plist->cur = plist->head->next;

    *pdata = plist->cur->data;
    return TRUE;
}
int LNext(List *plist, LData *pdata) {
    if(plist->cur->next == NULL) return FALSE;
    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

LData LRemove(List *plist) {
    Node* rpos = plist->cur;
    LData rdata = rpos->data;

    plist->before->next = rpos->next;
    plist->cur = plist->before;

    free(rpos);
    plist->numOfData--;
    return rdata;
}

int LCount(List *plist) {
    return plist->numOfData;
}

// SetSortRule 함수는 리스트의 멤버 comp를 초기화하는 함수이므로 다음과 같이 간단히 정의할 수 있다.
void SetSortRule(List *plist, int (*comp)(LData d1, LData d2)) {
    plist->comp = comp;
}
