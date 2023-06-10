#include <stdio.h>

int min;
int minFinder(int x) {
    if(min > x) min = x;
    return min;
}


int main(void) {
    int n;
    scanf("%d", &n);
    while(n--) {
        int a;
        scanf("%d", &a);
        min = minFinder(a);
    }
    printf("%d", min);
}