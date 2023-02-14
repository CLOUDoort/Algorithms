#include <stdio.h>
#include "../Chapter 09/UsefulHeap.c"
#include "../Chapter 09/UsefulHeap.h"

int PriComp(int n1, int n2) {
    // 오름차순 정렬 가능
    return n2-n1;
    // 내림차순은 n1-n2
}


void HeapSort(int arr[], int n, PriorityComp pc) {
    Heap heap;
    HeapInit(&heap, pc);
    for(int i = 0; i < n; i++) {
        HInsert(&heap, arr[i]);
    }
    // HDelete는 우선순위가 가장 높은 루트노드를 반환하기 때문에 정렬 가능
    for(int i = 0; i < n; i++) {
        arr[i] = HDelete(&heap);
    }
}

int main(void) {
    int arr[4] = {3, 4, 1, 2};
    HeapSort(arr, sizeof(arr)/sizeof(int), PriComp);
    for(int i = 0; i < 4; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}