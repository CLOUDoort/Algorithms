#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("사학과 2017116145 강준석\n");
    FILE *fp = fopen("in1.txt", "r");
    if(fp == NULL) printf("error\n");
    int n = 0;
    while(1) {
        if(feof(fp) != 0) break;
        int a;
        fscanf(fp, "%d", &a);
        n++;
    }
    fseek(fp, 0, SEEK_SET);

    int* L = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        fscanf(fp, "%d", &L[i]);
    }
    for(int i = 0; i < n-1; i++) {
        int tmp = L[i];
        int j = 0;
        for(j = 0; j < n; j++) {
            if(j != i) {
                if(tmp == L[j]) break;
            }
        }
        if(j == n) printf("%d ", L[i]);
    }

    fclose(fp);
}
