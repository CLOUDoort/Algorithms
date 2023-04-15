#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("Error\n");
        return 0;
    }
    int n; fscanf(fp, "%d", &n);
    int *arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++) fscanf(fp, "%d", &arr[i]);

    float sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    float ave = sum/n;

    float x = 0;
    for(int i = 0; i < n; i++) {
        x += pow(arr[i]-ave, 2);
    }
    printf("표준편차: %.2f\n", sqrt(x/n));
    

    fclose(fp);
    free(arr);
    return 0;
}