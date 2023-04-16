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
    int n = 0, m = 0;
    int cnt1 = 10, cnt2 = 10;
    int *arr1 = (int*)malloc(sizeof(int)*cnt1);
    int *arr2 = (int*)malloc(sizeof(int)*cnt2);

    while(fscanf(fp1, "%d", &arr1[n]) != EOF) {
        n++;
        if(n % 10 == 0) {
            if(!feof(fp1) && cnt1 < 110) {
                cnt1 += 10;
                int* new_arr1 = (int*)realloc(arr1, sizeof(int)*cnt1);
                arr1 = new_arr1;
            } 
        }
    }
    while(fscanf(fp2, "%d", &arr2[m]) != EOF) {
        m++;
        if(m % 10 == 0) {
            if(!feof(fp2) && cnt2 < 110) {
                cnt2 += 10;
                int* new_arr2 = (int*)realloc(arr2, sizeof(int)*cnt2);
                arr2 = new_arr2;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr1[i] == arr2[j]) printf("%d ", arr1[i]);
        }
    }    
    fclose(fp1); fclose(fp2);
    free(arr1); free(arr2);
    return 0;
}