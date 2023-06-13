#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 101

int a[MAX_ELEMENT];
int link[MAX_ELEMENT];

// 데이터 길이, 진수, 데이터 개수
int radixSort(int d, int r, int n);
int digit(int target, int d, int r);

int main() {
    FILE*fp1 = fopen("in1.txt", "r");
    if(fp1 == NULL) {
        printf("file read error\n");
        exit(1);
    }
    FILE*fp2 = fopen("out1.txt", "w");
    if(fp2 == NULL) {
        printf("file read error\n");
        exit(1);
    }
    int n = 1, input = 0;
    while(fscanf(fp1, "%d", &a[n]) != EOF) n++;
    n--;
    int first = radixSort(2, 10, n);

    for(int i = first; i > 0; i = link[i]) {
        fprintf(fp2, "%d ", a[i]);
    }

    fclose(fp1); fclose(fp2);
    return 0;
}

int digit(int target, int d, int r) {
    for(int i = d; i < 1; i++) {
        target /= r;
    }
    return target % r;
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
            bin = digit(a[current], i, r);
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