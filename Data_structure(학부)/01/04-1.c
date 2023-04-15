#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x, y) ((x) < (y) ? -1 : ((x) == (y)) ? 0 : 1)

int binarySearch(int arr[], int left, int right, int target);

int main() {
    FILE *fp = fopen("data2.txt", "r");
    if(fp == NULL) {
        printf("FILE Error\n");
        return 0;
    }
    int n;
    fscanf(fp, "%d", &n);
    int *arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++) fscanf(fp, "%d", &arr[i]);
    int target;
    scanf("%d", &target);
    int ans = binarySearch(arr, 0, n, target);

    if(ans != -1) printf("S(%d)", ans);
    else printf("F(-1)");

    fclose(fp);
    free(arr);
    return 0;
}

int binarySearch(int arr[], int left, int right, int target) {
    int middle;
    while(left <= right) {
        middle = (left+right)/2;
        switch(COMPARE(arr[middle], target)) {
            case -1: {
                left = middle+1;
                break;
            }
            case 0: return middle;
            case 1: {
                right = middle-1;
                break;
            }
        }
    }
    return -1;
}