// ArrarList의 ADT
// void ListInit(List *plist);
// void LInsert(List *plist, LData data);
// int LFirst(List *plist, LData *pdata); , true / false
// int LNext(List *plist, LData *pdata); , true / false 
// LData LRemove(List *plist); , 삭제된 데이터 반환
// int LCount(List *plist);
#include <stdio.h>
#include "ArrayList.h"

void ListInit(List *plist) {
    plist->numOfData = 0;
    plist->curPosition = -1;
}
void LInsert(List *plist, LData data) {
    if(plist->numOfData >= LIST_LEN) {
        puts("저장공간이 꽉 찼습니다! \n");
        return;
    }
    plist->arr[plist->numOfData] = data;
    plist->numOfData++;
}

int LFirst(List *plist, LData *pdata) {
    if(plist->numOfData == 0) return FALSE;
    *pdata = plist->arr[0];
    plist->curPosition = 0;
    return TRUE;
}
int LNext(List *plist, LData *pdata) {
    if(plist->curPosition >= plist->numOfData-1) return FALSE;
    plist->curPosition++;
    *pdata = plist->arr[plist->curPosition];
    return TRUE;
}

LData LRemove(List *plist) {
    LData data = plist->arr[plist->curPosition];
    for(int i = plist->curPosition; i < plist->numOfData-1; i++) {
        plist->arr[i] = plist->arr[i+1];
    }
    plist->curPosition--;
    plist->numOfData--;
    return data;
}

int LCount(List *plist) {
    return plist->numOfData;
}