/*
- 파일로부터 데이터 받아 리스트 만든다.
- quicksort해준다.
    - pivot값을 배열의 첫번째 원소 값으로 설정하여 비교하면서 정렬한다.
- 파일에 출력한다.
- 파일 닫는다.
*/

#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[20];

void quickSort(int left, int right);

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
    int cnt = 0;
    while(fscanf(fp1, "%d", &list[cnt++]) != EOF);
    cnt--;

    quickSort(0, cnt-1);
    for(int i = 0; i < cnt; i++) {
        fprintf(fp2, "%d ", list[i]);
    }
    fclose(fp1); fclose(fp2);
    return 0;
}

void quickSort(int left, int right) {
    int pivot, i, j, temp;
    if(left < right) {
        i = left, j = right+1;
        pivot = list[left];
        do {
            do {
                i++;
            } while(list[i] < pivot);
            do {
                j--;
            } while(list[j] > pivot);
            if(i < j) SWAP(list[i], list[j], temp);
        } while(i < j);
        SWAP(list[left], list[j], temp);
        quickSort(left, j-1);
        quickSort(j+1, right);
    }
}