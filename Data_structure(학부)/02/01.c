#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("Error\n");
        return 1;
    }
    int n;
    fscanf(fp, "%d", &n);
    int *arr = (int*)malloc(sizeof(int)*n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
        if(arr[i] >= 90) cnt++;
    }
    printf("%d\n", cnt);
    for(int i = 0; i < n; i++) {
        if(arr[i] >= 90) printf("%d\n", arr[i]);
    }
    free(arr);
    fclose(fp);
    return 0;
}