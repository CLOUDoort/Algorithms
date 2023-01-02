#include <stdio.h>
#include "ArrayList.c"
#include "ArrayList.h"

int main(void) {
    // ArrayList의 생성 및 초기화 //
    List list;
    int data, sum = 0;
    ListInit(&list);

    // 데이터 5개 저장 //
    for(int i = 0; i < 10; i++) LInsert(&list, i);

    // 저장된 데이터 합 출력 //
    printf("현재 데이터의 수 : %d \n", LCount(&list));
    if(LFirst(&list, &data)) {
        sum += data;
        while(LNext(&list, &data)) sum += data;
    }
    printf("현재 데이터의 합 : %d \n", sum);
    printf("\n\n");

    // 2의 배수 또는 3의 배수 삭제 // 
    if(LFirst(&list, &data)) {
        if(data % 2 == 0 || data % 3 == 0) LRemove(&list);
        while(LNext(&list, &data)) {
            if(data % 2 == 0 || data % 3 == 0) LRemove(&list);
        }
    }

    // 삭제 후 남은 데이터 모두 출력 // 
    printf("현재 데이터의 수 : %d \n", LCount(&list));
    if(LFirst(&list, &data)) {
        printf("%d ", data);
        while(LNext(&list, &data)) printf("%d ",data);
    }
    printf("\n\n");
    return 0;
}