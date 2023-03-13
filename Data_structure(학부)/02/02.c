#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
float avg;
void PrintCount(FILE *fp) {
    fscanf(fp, "%d", &n);
    printf("데이터 개수: %d\n",n);
}

void PrintAverage(int *arr, int n) {
    float sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    avg = sum/n;
    printf("평균: %.2f\n", avg);
}


/*
표준편차 구하는 함수
변수 x에 개별 관측값을 평균에서 뺀 값을 제곱하여 더해준다.
변수 x를 데이터의 개수로 나눠주고, 그 값의 제곱근을 구한다.
*/
void PrintStandardDeviation(int *arr) {
    float x = 0;
    for(int i = 0; i < n; i++) {
        x += pow(arr[i]-avg, 2);
    }
    printf("표준편차: %.2f\n", sqrt(x/n));
}

int main(void) {
    FILE *fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("Error\n");
        return 1;
    }
    PrintCount(fp);
    int *arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++) fscanf(fp, "%d", &arr[i]);
    PrintAverage(arr, n);
    PrintStandardDeviation(arr);

    free(arr);
    fclose(fp);
}