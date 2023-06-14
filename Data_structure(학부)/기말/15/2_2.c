#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 25

typedef struct element {
    char data;
} element;
element heap[MAX_ELEMENT];
int n = 0;

void init();
void inOrderTraversal(int i);

int main() {
    init();
    inOrderTraversal(1);
}

void inOrderTraversal(int i) {
    if(i*2 <= n) inOrderTraversal(i*2);
    printf("%c ", heap[i].data);
    if(i*2+1 <= n) inOrderTraversal(i*2+1);
}

void init() {
    FILE* fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("file read error\n");
        exit(1);
    }
    fscanf(fp, "%d", &n);
    for(int i = 1; i <= n; i++) {
        fscanf(fp, " %c", &heap[i].data);
    }
    fclose(fp);
}