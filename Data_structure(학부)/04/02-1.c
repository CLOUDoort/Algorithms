#include <stdio.h>
#include <stdlib.h>

int* makeArray(int n);
void initArray(FILE* fp, int* arr, int n);
int findMin(int* arr, int n);

int main() {
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("Error\n");
        return 0;
    }
    int n;
    fscanf(fp, "%d", &n);
    int* arr = makeArray(n);
    initArray(fp, arr, n);
    printf("%d\n", findMin(arr, n));
    free(arr); fclose(fp);
    return 0;
}

int findMin(int* arr, int n) {
    int min = 1000;
    for(int i = 0; i < n; i++) {
        if(min > arr[i]) min = arr[i];
    }
    return min;
}

void initArray(FILE* fp, int* arr, int n) {
    for(int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
}

int* makeArray(int n) {
    int* newArr = (int*)malloc(sizeof(*newArr)*n);
    return newArr;
}