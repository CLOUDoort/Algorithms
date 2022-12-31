#include <stdio.h>
#include "ArrayList.h"

int main(void) {
    // ArrayList의 생성 및 초기화 //
    List list;
    int data, sum = 0;
    ListInit(&list);

    // 데이터 저장 //
    for(int i = 1; i <= 9; i++) LInsert(&list, i);
    
    if(LFirst(&list, &data)) {
        sum += data;
        while(LNext(&list, &data)) sum += data;
    }

    if(LFirst(&list, &data)) {
        if(data % 2 == 0 || data % 3 == 0) LRemove(&list);
        while(LNext(&list, &data)) {
            if(data % 2 == 0 || data % 3 == 0) LRemove(&list);
        }
    }
    if(LFirst(&list, &data)) {
        printf("%d ", data);
        while(LNext(&list, &data)) printf("%d ",data);
    }
}