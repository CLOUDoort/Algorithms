#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void selectSort(int list[], int n);

int main() {
    FILE *fp = fopen("data2.txt", "r");
    if(fp == NULL) {
        printf("FILE Error\n");
        return 0;
    }
    int n;
    fscanf(fp, "%d", &n);
    int *arr = (int*)malloc(sizeof(int)*n);
    int i = 0;
    for(int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    selectSort(arr, n);
    
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    fclose(fp);
    return 0;
}

void selectSort(int list[], int n) {
    int minIdx, temp;
    for(int i = 0; i < n-1; i++) {
        minIdx = i;
        for(int j = i+1; j < n; j++) {
            if(list[minIdx] > list[j]) minIdx = j;
        }
        SWAP(list[i], list[minIdx], temp);
    }
}