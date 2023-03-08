#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("사학과 2017116145 강준석 \n");
    FILE *fp;
    int n;
    fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("error\n");
        return 0;
    }
    fscanf(fp, "%d", &n);
    printf("n: %d\n", n);
    int* arr = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) fscanf(fp, "%d", &arr[i]);
    int min = arr[0];
    int sed = 1000;
    for(int i = 0; i < n; i++) {
        if(arr[i] < min) {
            sed = min;
            min = arr[i];
        }
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] < sed && arr[i] != min) sed = arr[i];
    }
    printf("가장 작은 값: %d\n", min);
    printf("두번째로 작은 값: %d\n", sed);
    int x;
    while(1) {
        scanf("%d", &x);
        if(x > 0) break;
    }
    FILE *fp2 = fopen("out.txt", "w");
    if(fp2 == NULL) printf("error\n");
    printf("%d 의배수: ", x);
    for(int i = 0; i < n; i++) {
        if(arr[i] % x == 0) {
            fprintf(fp2, "%d ", arr[i]);
            fprintf(stdout, "%d ", arr[i]);
        }
    }


    fclose(fp);
    fclose(fp2);
    return 0;
}