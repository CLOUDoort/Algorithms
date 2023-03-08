#include <stdio.h>

int main(void) {
    FILE *fp = fopen("data1.txt", "r");
    if(fp == NULL) {
        fprintf(stderr, "error\n");
        return 0;
    }
    int n;
    fscanf(fp, "%d", &n);
    int min = 1000, i;
    while(n--) {
        fscanf(fp, "%d", &i);
        if(min > i) min = i;
    }
    printf("%d", min);
    fclose(fp);
}