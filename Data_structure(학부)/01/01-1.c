#include <stdio.h>

void findMin(int *min, int a);

int main() {
    int n;
    scanf("%d", &n);
    int a = 0;
    int min = 10000;
    while(n--) {
        scanf("%d", &a); 
        findMin(&min, a);
    }
    printf("%d", min);
    return 0;
}

void findMin(int *min, int a) {
    if(*min > a) *min = a;
}