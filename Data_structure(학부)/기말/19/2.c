/*
- 파일로부터 데이터 받고 merge sort 구현한다.
- 데이터 인덱스가 0이 아닌 1부터 시작한다는 것을 유의해야 한다.
*/

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
void mergePass(element init[], element mergeList [], int n, int s);
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

void mergePass(element initList[], element mergeList[], int n,  int s) {
    int i, j;
	for (i = 1; i <= n - 2 * s + 1; i += 2 * s)
		merge(initList, mergeList, i, i + s - 1, i + 2 * s - 1, command);
	if (i + s - 1 < n)
		merge(initList, mergeList, i, i + s - 1, n, command);
	else
		for (j = i; j <= n; j++)
			mergeList[j] = initList[j];
}

void merge(element initList[], element mergeList[], int i, int m, int n, char command) {
    int j, k, t;
    j = m+1;
    k = i;
    if(command == 'X') {
        while(i <= m && j <= n)  {
            if(initList[i].x <= initList[j].x) {
                mergeList[k++] = initList[i++];
            }
            else mergeList[k++] = initList[j++];
        }
    }
    else if(command == 'Y') {
        while(i <= m && j <= n) {
            if(initList[i].y <= initList[j].y) {
                mergeList[k++] = initList[i++];
            }
            else mergeList[k++] = initList[j++];
        }
    }
    else {
        while(i <= m && j <= n) {
            if(initList[i].z <= initList[j].z) {
                mergeList[k++] = initList[i++];
            }
            else mergeList[k++] = initList[j++];
        }
    }
    if(i > m) {
        for(t = j; t <= n; t++) {
            mergeList[t] = initList[t];
        }
    }
    else {
        for(t = i; t <= m; t++) {
            mergeList[k+t-i] = initList[t];
        }
    }
}

