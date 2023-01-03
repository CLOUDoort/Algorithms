#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.c"
#include "ArrayList.h"
#include "Point.h"
#include "Point.c"

int main(void) {
    // ArrayList의 생성 및 초기화 //
    List list;
    Point compPos;
    Point *ppos; // 구조체 변수의 주소값을 리스트에 저장할 것

    ListInit(&list);

    // 데이터 저장 //
    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);
    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);
    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);
    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);


    // 저장된 데이터 합 출력 //
    printf("현재 데이터의 수 : %d \n", LCount(&list));
    if(LFirst(&list, &ppos)) {
        ShowPointPos(ppos);
        while(LNext(&list, &ppos)) ShowPointPos(ppos);
    }
    printf("\n\n");

    compPos.xpos = 2;
    compPos.ypos = 0;

    // xpos가 2인 데이터 삭제
    if(LFirst(&list, &ppos)) {
        if(PointComp(ppos, &compPos) == 1) {
            ppos = LRemove(&list);
            free(ppos);
        }
        while(LNext(&list, &ppos)) {
            if(PointComp(ppos, &compPos) == 1) {
            ppos = LRemove(&list);
            free(ppos);
            }
        }
    }

    // 삭제 후 남은 데이터 모두 출력 // 
    printf("현재 데이터의 수 : %d \n", LCount(&list));
    if(LFirst(&list, &ppos)) {
        ShowPointPos(ppos);
        while(LNext(&list, &ppos)) ShowPointPos(ppos);
    }
    printf("\n\n");
    return 0;
}