#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int descendingSort(int *parr, int *count);

int main()
{
    int arr[10];
    int i;
    int count = 10;
    for(i = 0; i < count; i++) {
        scanf("%d", &arr[i]);
    }
    descendingSort(arr, &count);
    for(i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

int descendingSort(int *parr, int *count)
{
    int temp, i, j;
    for(i = 0; i < *count - 1; i++) {
        for(j = 0; j < *count -1 -i; j++) {
            if(parr[j] < parr[j+1]) {
                temp = parr[j+1];
                parr[j+1] = parr[j];
                parr[j] = temp;
            }
        }
    }
    return 0;
}