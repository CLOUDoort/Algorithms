#include <stdio.h>
#include <string.h>

void SequentialSearch(char arr[][4], char target[], int n);
void IterativeSearch(char arr[][4], char target[], int left, int right);
void RecursiveSearch(char arr[][4], char target[], int left, int right);

int main() {
    FILE *fp = fopen("list.txt", "r");
    if(fp == NULL) {
        printf("File Error\n");
        return 0;
    }
    char arr[20][4];
    int cnt = 0;
    while((fscanf(fp, "%s", arr[cnt])) != EOF) cnt++;

    char target[4];
    scanf("%s", target);
    SequentialSearch(arr, target, cnt);
    IterativeSearch(arr, target, 0, cnt);
    RecursiveSearch(arr, target, 0, cnt);
}

void SequentialSearch(char arr[][4], char target[], int n) {
    for(int i = 0; i < n; i++) {
        if(!strcmp(arr[i], target)) {
            printf("Sequential search result: S\n");
            return;
        }
    }
    printf("Sequential search result: F\n");
}
void IterativeSearch(char arr[][4], char target[], int left, int right) {
    int middle;
    while(left <= right) {
        middle = (left+right)/2;
        if(strcmp(arr[middle], target) == 0) {
            printf("Iterative binary search result: S\n");
            return;
        }
        else if(strcmp(arr[middle], target) < 0) {
            left = middle+1;
        }
        else {
            right = middle-1;
        }
    }
    printf("Iterative binary search result: F\n");
}
void RecursiveSearch(char arr[][4], char target[], int left, int right) {
    int middle;
    if(left <= right) {
        middle = (left+right)/2;
        if(strcmp(arr[middle], target) == 0) {
            printf("Recursive binary search result: S\n");
            return;
        }
        else if(strcmp(arr[middle], target) > 0) {
            RecursiveSearch(arr, target, left, middle-1);
        }
        else RecursiveSearch(arr,target, middle+1, right);
    }
    else printf("Recursive binary search result: F\n");
}