#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 11
#define HEAP_FULL(n) (n == MAX_ELEMENT-1)
#define HEAP_EMPTY(n) (!n)

typedef struct element {
    int key;
} element;
element heap[MAX_ELEMENT];
int n = 0;

void push(element item);
element pop();
void levelOrderTraversal();
void inOrderTraversal(int i);

int main() {
    FILE* fp = fopen("in1.txt", "r");
    if(fp == NULL) {
        printf("file read error\n");
        exit(1);
    }
    int value = 0;
    while(fscanf(fp, "%d", &value) != EOF) {
        element newElement; newElement.key = value;
        push(newElement);
    }
    inOrderTraversal(1);
    printf("\n");
    levelOrderTraversal();
    fclose(fp); 
    return 0;
}

void inOrderTraversal(int i) {
    if(i*2 <= n) inOrderTraversal(i*2);
    printf("%d ", heap[i].key);
    if(i*2+1 <= n) inOrderTraversal(i*2+1);
}

void levelOrderTraversal() {
    for(int i = 1; i <= n; i++) {
        printf("%d ", heap[i].key);
    }
}

void push(element item) {
    int i;
    if(HEAP_FULL(n)) {
        fprintf(stderr, "The heap is full\n");
        exit(1);
    }
    i = ++n;
    while((i != 1) && (item.key > heap[i/2].key)) {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}

element pop() {
    int parent, child;
    element item, temp;
    if(HEAP_EMPTY(n)) {
        fprintf(stderr, "The heap is empty\n");
        exit(1);
    }
    // 삭제할 노드
    item = heap[1];
    // 마지막 노드 복사 후, 데이터 수 -1
    temp = heap[n--];
    parent = 1; child = 2;
    while(child <= n) {
        if((child < n) && heap[child].key < heap[child+1].key) child++;
        if(temp.key >= heap[child].key) break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}