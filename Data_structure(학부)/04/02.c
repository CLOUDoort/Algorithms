/*
- 아이디어
    - in.txt에 데이터 입력해준다.
    - in.txt 파일을 열어 데이터 개수 n을 받는다.
    - n을 기반으로 동적 배열 생성해주는 함수 만든다.
    - in.txt파일로부터 데이터를 받아 배열에 입력하는 함수 만든다.
    - 최소값 찾는 함수 만든다.
    - 동적 할당 해제해준다.
    - 파일스트림 닫아준다.
*/

#include <stdio.h>
#include <stdlib.h>

int* makeArray(int n) {
    int* newArray = (int*)malloc(sizeof(int)*n);
    return newArray;
}

void initArray(FILE *fp, int* arr, int n) {
    for(int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
}

int findMin(int* arr, int n) {
    int min = arr[0];
    for(int i = 0; i < n; i++) {
        if(min > arr[i]) min = arr[i];
    }
    return min;
}

int main() {
    int n;
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("Error\n");
        return 1;
    }
    fscanf(fp, "%d", &n);
    int* arr = makeArray(n);
    initArray(fp, arr, n);
    printf("%d", findMin(arr, n));
    free(arr);
    fclose(fp);
}