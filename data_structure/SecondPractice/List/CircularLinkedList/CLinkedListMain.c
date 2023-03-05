#include <stdio.h>
#include "CLinkedList.h"
#include "CLinkedList.c"

int main(void) {
    List list;
    int data, i, nodeNum;
    ListInit(&list);

    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsertFront(&list, 2);
    LInsertFront(&list, 1);

    if(LFirst(&list, &data)) {
        printf("%d ", data);
        for(i = 0; i < LCount(&list)*3-1; i++) {
            if(LNext(&list, &data)) printf("%d ", data);
        }
    }
    printf("\n");

}