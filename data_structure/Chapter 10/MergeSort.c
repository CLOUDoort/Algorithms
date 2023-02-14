#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right) {
    // 왼쪽 배열의 첫번째 인덱스
    int fIdx = left;
    // 오른쪽 배열의 첫번째 인덱스
    // 하나하나 비교하며 작은 값을 새롭게 할당한 배열에 저장한 뒤 다시 기존 배열에 복사
    int rIdx = mid+1;
    int i;

    // 정렬할 배열 할당
    int *sortArr = (int*)malloc(sizeof(int)*(right+1));
    int sIdx = left; // 새로 할당한 배열 인덱스

    while(fIdx <= mid && rIdx <= right) {
        if(arr[fIdx] <= arr[rIdx]) sortArr[sIdx] = arr[fIdx++];
        else sortArr[sIdx] = arr[rIdx++];
        sIdx++;
    }

    // 배열의 앞부분이 모두 sortArr에 담겨졌을 경우 배열의 뒷부분에 남은 데이터들을 sortArr에 그대로 옮긴다.
    if(fIdx > mid) {
        for(i = rIdx; i <= right; i++, sIdx++) sortArr[sIdx] = arr[i];
    } 
    // 배열의 뒷부분이 모두 sortArr에 담겨졌을 경우 배열의 앞부분에 남은 데이터를들 sortArr에 그대로 옮긴다.
    else {
        for(i = fIdx; i <= mid; i++, sIdx++) sortArr[sIdx] = arr[i];
    }
    // 정렬한 배열을 기존배열에 복사
    for(i = left; i <= right; i++) arr[i] = sortArr[i];
    
    free(sortArr);
}

void MergeSort(int arr[], int left, int right) {
    int mid;
    if(left < right) {
        mid = (left+right)/2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);

        // 병합
        MergeTwoArea(arr, left, mid, right);
    }
}

int main(void) {
    int arr[7] = {3, 2, 4, 1, 7, 6, 5};
    int i;

    MergeSort(arr, 0, sizeof(arr)/sizeof(int));
    for(i = 0; i < 7; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}