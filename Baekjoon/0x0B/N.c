#include <stdio.h>

void Print(int n) {
    if(n == 0) return;  
    printf("%d ", n);
    Print(n-1);
}

int Sum(int n) {
    if(n == 0) return 0;
    return n+Sum(n-1);
}

int main(void) {
    Print(100);
    printf("\n");
    printf("합 : %d \n", Sum(100));
}