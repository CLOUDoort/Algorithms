#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 101

char a[MAX_ELEMENT][6];
int link[MAX_ELEMENT];

int radixSort(int d, int r, int n);
int digit(char target[], int d, int r);

int main() {
    FILE*fp1 = fopen("in.txt", "r");
    if(fp1 == NULL) {
        printf("file read error\n");
        exit(1);
    }
    FILE*fp2 = fopen("out.txt", "w");
    if(fp2 == NULL) {
        printf("file read error\n");
        exit(1);
    }
    int n = 1;
    while(fscanf(fp1, "%s", a[n]) != EOF) n++;
    n--;
    int first = radixSort(5, 26, n);
    for(int i = first; i > 0; i = link[i]) {
        fprintf(fp2, "%s ", a[i]);
    }

    fclose(fp1); fclose(fp2);
    return 0;
}

int digit(char target[], int d, int r) {
    if(!target[d]) return 0;
    return target[d]-'0'-49;
}

int radixSort(int d, int r, int n) {
    int front[r], rear[r];
    int i, first, last, bin, current;
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