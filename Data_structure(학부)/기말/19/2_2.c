#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 10

typedef struct element {
    int x;
    int y;
    int z;
} element;
int cnt = 1;
element list[MAX_ELEMENT];
char command;

void mergeSort(int n);
void mergePass(element init[], element mergeList[], int n, int s);
void merge(element init[], element mergeList[], int i, int m, int n, char command);

int main() {
    FILE *fp1 = fopen("in.txt", "r");
    if(fp1 == NULL) {
        printf("File read error\n");
        exit(1);
    }
    FILE *fp2 = fopen("out.txt", "w");
    if(fp2 == NULL) {
        printf("File read error\n");
        exit(1);
    }
    while(fscanf(fp1, "%d %d %d", &list[cnt].x, &list[cnt].y, &list[cnt].z) != EOF) {
        cnt++;
    }
    cnt--;
    scanf(" %c", &command);
    mergeSort(cnt);
    for(int i = 1; i <= cnt; i++) {
        fprintf(fp2, "%d %d %d\n", list[i].x, list[i].y, list[i].z);
    }

    fclose(fp1); fclose(fp2);
    return 0;
}

void mergeSort(int n) {
    int s = 1;
    element tempList[MAX_ELEMENT];
    while(s < n) {
        mergePass(list, tempList, n, s);
        s *= 2;
        mergePass(tempList, list, n, s);
        s *= 2;
    }
}

void mergePass(element initList[], element mergeList[], int n, int s) {
    int i, j;
    for(i = 1; i <= n-2*s+1; i += 2*s) {
        merge(initList, mergeList, i, i+s-1, i+2*s-1, command);
    }
    if(i+s-1 < n) {
        merge(initList, mergeList, i, i +s-1, n, command);
    }
    else {
        for(j = i; j <= n; j++) {
            mergeList[j] = initList[i];
        }
    }
}

