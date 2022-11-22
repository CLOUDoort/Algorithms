#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ascendingSort(int *parr, int count);

int main()
{
    int arr[10];
    int i;
    int count = 10;

    for(i = 0; i < count; i++) {
        scanf("%d", &arr[i]);
    }
    ascendingSort(arr, count);
    for(i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void ascendingSort(int *parr, int count)
{
    int temp, i, j;
    for(i = 0; i < count - 1; i++) {
        for(j = 0; j < count - 1 - i; j++) {
            if(parr[j] > parr[j+1]) {
                temp = parr[j];
                parr[j] = parr[j+1];
                parr[j+1] = temp;
            }
        }
    }
}