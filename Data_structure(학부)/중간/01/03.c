#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void selectionSort(int arr[], int n) {
    int minIdx;
    int temp;
    for(int i = 0; i < n-1; i++) {
        minIdx = i;
        for(int j = i+1; j < n; j++) {
            if(arr[minIdx] > arr[j]) {
                minIdx = j;
            }
        }
        SWAP(arr[i], arr[minIdx], temp);
    }
}

int main(void) {
    FILE *fp = fopen("data2.txt", "r");
    if(fp == NULL) {
        fprintf(stderr, "error\n");
        return 0;
    }
    int n;
    fscanf(fp, "%d", &n);
    int *arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++) fscanf(fp, "%d", &arr[i]);
    selectionSort(arr, n);

    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    free(arr);
    fclose(fp);
}