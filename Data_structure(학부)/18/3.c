/*
- 파일로부터 데이터 받아 리스트 만든다.
- qsort 함수를 이용하여 정렬한다.
- 파일 닫는다.
*/

#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[20];

int compare(const void* a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("File read error\n");
        exit(1);
    }
    int cnt = 0;
    while(fscanf(fp, "%d", &list[cnt++]) != EOF);
    cnt--;

    qsort(list, cnt, sizeof(int), compare);
    for(int i = 0; i < cnt; i++) {
        printf("%d ", list[i]);
    }
    fclose(fp);
    return 0;
}