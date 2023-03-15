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
    int cnt1 = 0;
    while(fscanf(fp1, "%d", &arr1[n1]) != EOF) {
        n1++;
        // 데이터 개수가 10의 배수일 때
        // 파일 끝 도달했을 경우
        if(n1 % 10 == 0) {
            if(!feof(fp1)) {
            // 110개 이상 할당하지 않은 경우, 10개 다시 할당
                if(cnt1 < 11) {
                    int *new_arr1 = (int*)realloc(arr1, 10*sizeof(int));
                    arr1 = new_arr1;
                    cnt1++;
                }
            }
        }
    }
    int *arr2 = (int*)malloc(sizeof(int)*10);
    int n2 = 0;
    int cnt2 = 0;
    while(fscanf(fp2, "%d", &arr2[n2]) != EOF) {
        n2++;
        // 데이터 개수가 10의 배수일 때
        // 파일 끝 도달했을 경우
        if(n2 % 10 == 0) {
            if(!feof(fp2)) {
            // 110개 이상 할당하지 않은 경우, 10개 다시 할당
                if(cnt2 < 11) {
                    int *new_arr2 = (int*)realloc(arr2, 10*sizeof(int));
                    arr2 = new_arr2;
                    cnt2++;
                }
            }
        }
    }

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