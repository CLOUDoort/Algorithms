/*
- 파일로부터 데이터 입력받아 리스트 만든다.
- insert sort 이용하여 정렬한다.
    - index 0은 임시 저장소로 사용하고, index 1부터 정렬하는데, 1은 이미 정렬되어 있다고 가정한다.
    - 그래서 index 2부터 시작하여 비교하고 정렬한다.
- 파일 닫는다.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int key;
    char name[10];
    int grade;
} element;

element list[10];

void insert(element e, int i);

int main() {
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("File read error\n");
        exit(1);
    }
    int n;
    fscanf(fp, "%d", &n);
    for(int i = 1; i <= n; i++) {
        fscanf(fp, "%d %s %d", &list[i].key, list[i].name, &list[i].grade);
    }

    for(int i = 2; i <= n; i++) {
        element temp = list[i];
        insert(temp, i-1);
    }

    printf("\n");
    for(int i = 1; i <= n; i++) {
        printf("%d %s %d\n", list[i].key, list[i].name, list[i].grade);
    }
    fclose(fp);
    return 0;
}

void insert(element e, int i) {
    list[0] = e;
    while(e.key < list[i].key) {
        list[i+1] = list[i];
        i--;
    }
    list[i+1] = e;
}

