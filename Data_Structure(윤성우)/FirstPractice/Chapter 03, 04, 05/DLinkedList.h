#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node {
    LData data;
    struct _node* next;
} Node;

typedef struct _linkedList {
    Node* head;
    Node* cur;
    Node* before; // 노드의 삭제와 관련이 있다.
    int numOfData;
    int (*comp)(LData d1, LData d2); // d1과 d2를 인자로 갖는 함수의 주소값을 리턴
} LinkedList;

typedef LinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);

int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);

LData LRemove(List* plist);
int LCount(List* plist);

// SetSortRule 함수가 호출되면서 정렬의 기준이 리스트의 멤버 comp에 등록되고나면, SInsert 함수 내에서는 comp에 등록된 정렬의 기준을 근거로 데이터를 정렬하여 저장한다.
void SetSortRule(List* plist, int (*comp)(LData d1, LData d2));

#endif