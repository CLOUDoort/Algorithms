// 2017116145-강준석
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENT 100
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

typedef struct element {
    int x;
    char y[11];
    float z;
} element;
element heap[MAX_ELEMENT];

void heapSort(int n, char key);
void adjust(int root, int n, char key);

int main() {
    FILE* fp = fopen("in1.txt", "r");
    if(fp == NULL) {
        printf("file read error\n");
        exit(1);
    }
    int n = 1;
    while(fscanf(fp, "%d %s %f", &heap[n].x, heap[n].y, &heap[n].z) != EOF) {
        n++;
    }
    n -= 1;

    char key;
    scanf(" %c", &key);
    heapSort(n, key);
    for(int i = 1; i <= n; i++) {
        printf("%d  %8s %11.1f\n", heap[i].x, heap[i].y, heap[i].z);
    }
    fclose(fp);
    return 0;
}

void heapSort(int n, char key) {
    int i, j;
    element temp;
    for(i = n/2; i > 0; i--) {
        adjust(i, n, key);
    }
    for(i = n-1; i > 0; i--) {
        SWAP(heap[1], heap[i+1], temp);
        adjust(1, i, key);
    }
}

void adjust(int root, int n, char key) {
    int child, rootkey;
    char charKey[11];
    element temp = heap[root];
    child = 2*root;
    if(key == 'X') {
        rootkey = heap[root].x;
        while(child <= n) {
            if((child < n) && (heap[child].x < heap[child+1].x)) child++;
            if(rootkey > heap[child].x) break;
            else {
                heap[child/2] = heap[child];
                child *= 2;
            }
        }
        heap[child/2] = temp;
    }
    else if(key == 'Y') {
        strcpy(charKey, heap[root].y);
        while(child <= n) {
            if((child < n) && (strcmp(heap[child].y, heap[child+1].y) < 0)) child++;
            if(strcmp(charKey, heap[child].y) > 0) break;
            else {
                heap[child/2] = heap[child];
                child *= 2;
            }
        }
        heap[child/2] = temp;
    }
    else if(key == 'Z') {
        rootkey = heap[root].z;
        while(child <= n) {
            if((child < n) && (heap[child].z < heap[child+1].z)) child++;
            if(rootkey > heap[child].z) break;
            else {
                heap[child/2] = heap[child];
                child *= 2;
            }
        }
        heap[child/2] = temp;
    }
}