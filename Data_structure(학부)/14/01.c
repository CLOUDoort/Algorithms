/*
- 파일 열고 데이터 개수와 데이터를 읽고 Max heap을 구성하고 차례대로 출력한다.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 11
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

typedef struct {
    int key;
} element;
element heap[MAX_ELEMENTS];
int n = 0;

void push(element item);

int main() {
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("file read error\n");
        exit(1);
    }
    int cnt = 0;
    int value = 0;
    fscanf(fp, "%d", &cnt);
    while(cnt--) {
        element newElement;
        fscanf(fp, "%d", &newElement.key);
        push(newElement);
        value++;
    }
    for(int i = 1; i <= value; i++) {
        printf("%d ", heap[i].key);
    }
    fclose(fp);
    return 0;
}

void push(element item) {
    int i = 0;
    if(HEAP_FULL(n)) {
        fprintf(stderr, "The heap is full. \n");
        exit(1);
    }
    i = ++n;
    while((i != 1) && (item.key > heap[i/2].key)) {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}