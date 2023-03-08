#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("error\n");
        return 0;
    }
    int n;
    fscanf(fp, "%d", &n);
    printf("n: %d\n", n);
    int *L = (int *)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++) fscanf(fp, "%d", L[i]);
    int min = L[0], second = 1000;
    for(int i = 0; i < n; i++) {
        if(L[i] < min) {
            second = min;
            min = L[i];
        }
        else if(L[i] < second && L[i] != min) second = L[i];
    }
    int x;
    scanf("%d", &x);
    for(int i = 0; i < n; i++) {
        if(L[i] % x == 0) {
            fprintf(fp, "%d", L[i]);
            fprintf(stdout, "%d", L[i]);
        }
    }
}