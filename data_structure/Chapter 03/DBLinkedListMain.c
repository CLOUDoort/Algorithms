#include <stdio.h>
#include "DBLinkedList.h"
#include "DBLinkedList.c"

int main(void) {
    List list;
    int data;
    ListInit(&list);

    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsert(&list, 6);
    LInsert(&list, 7);
    LInsert(&list, 8);

    if(LFirst(&list, &data)) {
        printf("%d ", data);
        while(LNext(&list, &data)) printf("%d ", data);
        printf("\n\n");
    }

    if(LFirst(&list, &data)) {
        if(data % 2 == 0)  {
            Data repoData = LRemove(&list);
            printf("삭제 데이터 : %d \n", repoData);
        }
        while(LNext(&list, &data)) {
            if(data % 2 == 0) {
                LRemove(&list);
                Data repoData = LRemove(&list);
                printf("삭제 데이터 : %d \n", repoData);
            }
        }
    }
    return 0;
}