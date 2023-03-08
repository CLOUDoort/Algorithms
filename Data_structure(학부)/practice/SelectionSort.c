#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 101

void sort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = arr[i];
    }
}

int main(void) {
    int list[MAX_SIZE];
    int i, n;

    printf("Enter the number of numbers to generate: ");
    scanf("%d", &n);
    if(n < 1 || n > MAX_SIZE) {
        fprintf(stderr, "Improper value of n\n");
        exit(-1);
    }
    for(int i = 0; i < n; i++) {
        list[i] = rand()%10000;
        printf("%d ", list[i]);
    }
    sort(list, n);
    printf("\n Sorted array: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}