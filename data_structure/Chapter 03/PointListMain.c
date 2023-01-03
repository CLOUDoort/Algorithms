#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.c"
#include "ArrayList.h"
#include "NameCard.h"
#include "NameCard.c"

int main(void) {
    // ArrayList의 생성 및 초기화 //
    List list;
    NameCard *card;
    ListInit(&list);

    // 데이터 저장 //
    card = MakeNameCard("junseok", "12345678");
    LInsert(&list, card);
    card = MakeNameCard("jun", "56781234");
    LInsert(&list, card);
    card = MakeNameCard("seok", "13243546");
    LInsert(&list, card);
    
    // 저장된 데이터 수 출력 //
    printf("현재 데이터의 수 : %d \n", LCount(&list));

    // 특정 대상 이름 탐색, 정보 출력
    if(LFirst(&list, &card)) {
        if(!NameCmp(card, "jun")) ShowNameCardInfo(card);
        while(LNext(&list, &card)) {
            if(!NameCmp(card, "jun")) ShowNameCardInfo(card);
        }
    }
    printf("\n\n");

    // 특정 대상 이름 탐색, 전화번호 변경
    if(LFirst(&list, &card)) {
        if(!NameCmp(card, "junseok")) ChangePhoneNum(card, "88888888");
        while(LNext(&list, &card)) {
            if(!NameCmp(card, "junseok")) ChangePhoneNum(card, "88888888");
        }
    }

    // 특정 대상 이름 탐색 데이터 삭제
    if(LFirst(&list, &card)) {
        if(!NameCmp(card, "seok")) {
            card = LRemove(&list);
            free(card);
        }
        while(LNext(&list, &card)) {
            if(!NameCmp(card, "seok")) {
                card = LRemove(&list);
                free(card);
            }
        }
    }
    
    // 삭제 후 남은 데이터 모두 출력 // 
    printf("현재 데이터의 수 : %d \n", LCount(&list));
    if(LFirst(&list, &card)) {
        ShowNameCardInfo(card);
        while(LNext(&list, &card)) ShowNameCardInfo(card);
    }
    printf("\n\n");
    return 0;
}