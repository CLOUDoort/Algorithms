#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp = fopen("in1.txt", "r");
    if(fp == NULL) {
        printf("error\n");
        return 0;
    }
    int n = 0;
    while(1) {
        if(feof(fp) != 0) break;
        int a;
        fscanf(fp, "%d", &a);
        n++;
    }
    fseek(fp, 0, SEEK_SET);
    int *L = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++) fscanf(fp, "%d", &L[i]);

    for(int i = 0; i < n-1; i++) {
        int j = 0;
        for(j = 1; j < n; j++) {
            if(i != j) {
                if(L[i] == L[j]) break;
            }
        }
        if(j == n) printf("%d ", L[i]);
    }
    fclose(fp);
}