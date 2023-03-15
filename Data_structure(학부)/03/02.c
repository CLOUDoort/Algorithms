#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp1 = fopen("data1.txt", "r");
    if(fp1 == NULL) {
        printf("Error\n");
        return 1;
    }
    FILE *fp2 = fopen("data2.txt", "r");
    if(fp2 == NULL) {
        printf("Error\n");
        return 1;
    }
    int *arr1 = (int*)malloc(sizeof(int)*10);
    int n1 = 0;
    while(fscanf(fp1, "%d", &arr1[n1]) != EOF) n1++;
    int *arr2 = (int*)malloc(sizeof(int)*10);
    int n2 = 0;
    while(fscanf(fp2, "%d", &arr2[n2]) != EOF) n2++;

    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            if(arr1[i] == arr2[j]) printf("%d ", arr1[i]);
        }
    }
    free(arr1);
    free(arr2);
    fclose(fp1);
    fclose(fp2);
    return 0;
}