#include <stdio.h>
#include <string.h>

int n;
void SequentialSearch(char arr[][4], int n, char* target) {
    for(int i = 0; i < n; i++) {
        if(strcmp(arr[i], target) == 0) {
            printf("Sequential search result: S\n");
            return;
        }
    }
    printf("Sequential search result: F\n"); 
}

void BinarySearch(char arr[][4], int n, char* target) {
    int first = 0;
    int last = n-1;
    while(first <= last) {
        int mid = (first+last)/2;
        if(strcmp(arr[mid], target) == 0) {
            printf("Iterative binary search result: S\n");
            return;
        }
        else if(strcmp(arr[mid], target) > 0) {
            last = mid-1;
        }
        else first = mid+1;
    }
    printf("Iterative binary search result: F\n");
}

void RecursiveBinarySearch(char arr[][4], int first, int last, char* target) {
    // Recursive는 while이 아닌 if
    if(first <= last) {
        int mid = (first+last)/2;
        if(strcmp(arr[mid], target) == 0) {
            printf("Recursive binary search result: S\n");
            return;
        }
        else if(strcmp(arr[mid], target) > 0) {
            RecursiveBinarySearch(arr, first, mid-1, target);
        }
        else RecursiveBinarySearch(arr, mid+1, last, target);
    }
    else printf("Recursive binary search result: F\n");
}

int main(void) {
    FILE *fp = fopen("list.txt", "r");
    if(fp == NULL) {
        printf("Error\n");
        return 1;
    }
    // 문자열은 3개, 데이터 개수는 20이하의 2차원 배열
    char arr[25][4];
    // 데이터 개수 구하면서 arr에 값 담기
    while(fscanf(fp, "%s", arr[n]) != EOF) n++;
    char target[4];
    scanf("%s", target);
    SequentialSearch(arr, n, target);
    BinarySearch(arr, n, target);
    RecursiveBinarySearch(arr, 0, n-1, target);

    fclose(fp);
}