/*
- 파일로부터 데이터 읽어들이고 Max heap을 구성한다.
- 다만 마지막 데이터는 pop을 해야 하는 숫자이기 때문에 따로 저장한 후, 그 수만큼 pop해준다.
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
element pop();

int main() {
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("file read error\n");
        exit(1);
    }
    element newElement;
    int cnt = 0;
    int popCnt = 0;
    while(fscanf(fp, "%d", &newElement.key) != EOF) {
        if(feof(fp)) {
            popCnt = newElement.key;
            break;
        }
        push(newElement);
        cnt++;
    }
    for(int i = 1; i <= cnt; i++) {
        printf("%d ", heap[i].key);
    }
    printf("\n");
    while(popCnt--) {
        pop();
        cnt--;   
    }
    for(int i = 1; i <= cnt; i++) {
        printf("%d ", heap[i].key);
    }
    fclose(fp);
    return 0;
}

element pop() {
    int parent, child;
    element item, temp;
    if(HEAP_EMPTY(n)) {
        fprintf(stderr, "The heap is empty\n");
        exit(1);
    }
    item = heap[1]; temp = heap[n--];
    parent = 1; child = 2;
    while(child <= n) {
        if((child < n) && (heap[child].key < heap[child+1].key))  child++;
        if(temp.key >= heap[child].key) break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return temp;
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
