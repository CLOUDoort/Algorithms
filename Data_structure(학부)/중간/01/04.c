#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int arr[], int left, int right, int target) {
    int mid;
    while(left <= right) {
        mid = (left+right)/2;
        if(target > arr[mid]) left = mid+1;
        else if(target == arr[mid]) return mid;
        else right = mid-1;
    }
    return -1;
}

int main(void) {
    FILE *fp = fopen("data2.txt", "r");
    if(fp == NULL) {
        fprintf(stderr, "error\n");
        return 0;
    }
    int target;
    scanf("%d", &target);
    int n;
    fscanf(fp, "%d", &n);
    int *arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++) fscanf(fp, "%d", &arr[i]);
    int idx = BinarySearch(arr, 0, n-1, target);

    if(idx == -1) printf("F(-1)");
    else printf("S(%d)", idx);
    free(arr);
    fclose(fp);
    return 0;
}