#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter the number of integers to allocate: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(sizeof(int)*n);
    if(arr == NULL) {
        printf("Error\n");
        return 1;
    }
    for(int i = 0; i < n; i++) arr[i] = i;
    printf("Allocated integers: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}