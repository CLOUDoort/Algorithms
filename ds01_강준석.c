#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("2017116145 강준석\n");
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("error\n");
        return 0;
    }
    int n;
    fscanf(fp, "%d", &n);
    printf("n: %d\n", n);
    int *L = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++) fscanf(fp, "%d", &L[i]);
    int min = L[0], second = 1000;
    for(int i = 0; i < n; i++) {
        if(L[i] < min) {
            second = min;
            min = L[i];
        }
        else if(L[i] < second && L[i] != min) second = L[i];
    }
    printf("가장 작은 값: %d\n", min);
    printf("두번째로 작은 값: %d\n", second);
    int x;
    while(1) {
        scanf("%d", &x);
        if(x > 0) break;
    }
    printf("%d의배수: ", x);
    for(int i = 0; i < n; i++) {
        if(L[i] % x == 0) {
            fprintf(fp, "%d", L[i]);
            fprintf(stdout, "%d", L[i]);
        }
    }
}