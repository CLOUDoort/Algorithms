#include <stdio.h>

void SelSort(int arr[], int n) {
    int i, j, temp, maxIdx;

    // 오름차순일 경우 첫번째 자료를 선택해서 나머지 자료들과 비교하여 최솟값을 첫번째 자리와 교체
    // 이를 반복
    for(i = 0; i < n-1; i++) {
        maxIdx = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[maxIdx]) maxIdx = j;
        }
        temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}

int main(void) {
    int arr[4] = {3, 4, 2, 1};
    int i;

    SelSort(arr, sizeof(arr)/sizeof(int));
    for(i = 0; i < 4; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}