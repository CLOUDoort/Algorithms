#include <stdio.h>

void InsertSort(int arr[], int n) {
    int i, j, insData;
    // 두 번째 자료부터 시작해서 그 앞의 자료들과 비교하여 삽입할 위치를 지정한 후 자료를 뒤로 옮기고 지정한 자리에 삽입하여 정렬하는 알고리즘이다.
    for(i = 1; i < n; i++) {
        insData = arr[i];
        for(j = i-1; j >= 0; j--) {
            if(arr[j] > insData) arr[j+1] = arr[j];
            else break;
        }
        arr[j+1] = insData;
    }
}

int main(void) {
    int arr[5] = {5, 3, 2, 4, 1};
    InsertSort(arr, sizeof(arr)/sizeof(int));
    for(int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}