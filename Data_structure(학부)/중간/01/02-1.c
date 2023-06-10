#include <stdio.h>

void findMin(int *min, int a);

int main() {
    FILE *fp = fopen("data1.txt", "r");
    if(fp == NULL) {
        printf("FILE Error\n");
        return 0;
    }
    int n, a, min = 10000;
    fscanf(fp, "%d", &n);
    while(n--) {
        fscanf(fp, "%d", &a);
        findMin(&min, a);
    }
    printf("%d", min);
    fclose(fp);
    return 0;
}

void findMin(int *min, int a) {
    if(*min > a) *min = a;
}