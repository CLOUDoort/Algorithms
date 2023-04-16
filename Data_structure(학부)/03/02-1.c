#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp1 = fopen("data1.txt", "r");
    if(fp1 == NULL) {
        printf("File Error\n");
        return 0;
    }
    FILE *fp2 = fopen("data2.txt", "r");
    if(fp2 == NULL) {
        printf("File Error\n");
        return 0;
    }
    int *arr1 = (int*)malloc(sizeof(int)*10);
    int *arr2 = (int*)malloc(sizeof(int)*10);

    int i = 0, j = 0;
    while(fscanf(fp1, "%d", &arr1[i]) != EOF) i++;
    while(fscanf(fp2, "%d", &arr2[j]) != EOF) j++;

    for(int n = 0; n < i; n++) {
        for(int m = 0; m < j; m++) {
            if(arr1[n] == arr2[m]) printf("%d ", arr1[n]);
        }
    }

    fclose(fp1);
    fclose(fp2);
    free(arr1);
    free(arr2);
    return 0;
}