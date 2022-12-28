// 계산기
#include <stdio.h>
int main()
{
    int arr[100];
    int cal[10];
    int i = 0;;
    // 100개까지 계산 가능
    printf("계산 시작!");
    while(1) {
        scanf("%d %d", &arr[i], &cal[i]);
        i++;
    }
}