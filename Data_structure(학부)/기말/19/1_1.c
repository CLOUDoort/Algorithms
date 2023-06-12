#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 20
#define HEAP_FULL(n) ((n) == MAX_ELEMENT-1)
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int heap[MAX_ELEMENT];
int n = 1;

void push(int data);
void heapSort();
void adjust(int root, int num);

int main() {
    FILE *fp1 = fopen("in.txt", "r");
    if(fp1 == NULL) {
        printf("File1 read error\n");
        exit(1);
    }
    FILE *fp2 = fopen("out.txt", "w");
    if(fp2 == NULL) {
        printf("File2 read error\n");
        exit(1);
    }
    int input;
    while(fscanf(fp1, "%d", &input) != EOF) {
        push(input);
    }
    n--;
    heapSort();
    for(int i = n; i > 0; i--) {
        fprintf(fp2, "%d ", heap[i]);
    }
    
    fclose(fp1); fclose(fp2);
    return 0;
}

void heapSort() {
    int i, temp;
    for(i = n/2; i > 0; i--) {
        adjust(i, n);
    }
    for(i = n-1; i > 0; i--) {
        SWAP(heap[1], heap[i+1], temp);
        adjust(1, i);
    }
}

void adjust(int root, int num) {
    int rootKey = heap[root];
    int child = 2*root;
    while(child <= num) {
        if((child < num) && heap[child] < heap[child+1]) {
            child++;
        }
        if(rootKey > heap[child]) break;
        else {
            heap[child/2] = heap[child];
            child *= 2;
        }
    }
    heap[child/2] = rootKey;
}

void push(int data) {
    if(HEAP_FULL(n)) {
        printf("Heap full\n");
        exit(1);
    }
    heap[n++] = data;
}