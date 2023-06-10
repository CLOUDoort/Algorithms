/*
- 파일로부터 데이터 입력받아서 배열 생성하고 배열을 이어줄 link 배열도 선언한다.
- radix sort함수를 작성한다.
    - front배열과 rear배열을 선언한다.
    - link 배열 초기화해준다.
    - 데이터 자리수만큼 for문을 돌려준다.
        - front 배열 초기화해준다.
        - 배열 데이터에서 LSD 방식으로 각 자리수 추출하는 character 함수 생성해준다.
            - 자리수가 비어있으면 0을 리턴하고 아니면 '0'을 빼주고 49를 빼준다. 그래야 front와 rear가 0부터 25까지 적절히 분배된다.
        - 받은 자리수를 index로 하는 front 배열에 배열 데이터 넣어준다.
            - 이미 있다면 이전 배열 데이터의 link를 업데이트 해준다.
        - rear 배열 업데이트해준다.
    - 비어있지 않은 front 배열과 rear 배열의 index를 찾는다.
    - first index를 리턴한다.
- 받은 first index로 정렬한 데이터를 파일에 출력한다.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

char a[MAX_ELEMENT][6];
int link[MAX_ELEMENT];

int character(char target[], int i, int r);
int radixSort(int d, int r, int n);

int main() {
    FILE *fp1 = fopen("in.txt", "r");
    if(fp1 == NULL) {
        printf("file read error\n");
        exit(1);
    }
    FILE *fp2 = fopen("out.txt", "w");
    if(fp2 == NULL) {
        printf("file read error\n");
        exit(1);
    }
    int n = 1;
    while(fscanf(fp1, "%s", a[n++]) != EOF);
    n -= 2;
    int first_index = radixSort(5, 26, n);
    for(int i = first_index; i > 0; i = link[i]) {
        fprintf(fp2 ,"%s ", a[i]);
    }
    fclose(fp1); fclose(fp2);
    return 0;
}

int character(char target[], int i, int d) {
    if(!target[i]) return 0;
    return target[i]-'0'-49;
}

int radixSort(int d, int r, int n) {
    int front[r], rear[r];
    int i, bin, current, first, last;
    first = 1;
    for(i = 1; i < n; i++) link[i] = i+1;
    link[n] = 0;
    for(i = d-1; i >= 0; i--) {
        for(bin = 0; bin < r; bin++) front[bin] = 0;
        for(current = first; current; current = link[current]) {
            bin = character(a[current], i, r);
            if(front[bin] == 0) front[bin] = current;
            else link[rear[bin]] = current;
            rear[bin] = current;
        }
        for(bin = 0; !front[bin]; bin++);
        first = front[bin]; last = rear[bin];
        for(bin++; bin < r; bin++) {
            if(front[bin]) {
                link[last] = front[bin];
                last = rear[bin];
            }
        }
        link[last] = 0;
    }
    return first;
}