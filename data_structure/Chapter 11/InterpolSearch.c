#include <stdio.h>

int ISearch(int arr[], int first, int last, int target) {
    int mid;

    // 탐색 대상이 존재하지 않을 경우, 탐색 대상의 값은 탐색 범위의 값을 넘어선다는 사실을 근거로 탈출 조건 바꿔준다.
    if(arr[first] > target || arr[last] < target) return -1;

    mid = ((double)target-arr[first]) / (arr[last]-arr[first]) * (last-first) + first;

    if(arr[mid] == target) return mid;
    else if(target < arr[mid]) return ISearch(arr, first, mid-1, target);
    else return ISearch(arr, mid+1, last, target); 
}

int main(void) {
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 7);
    if(idx == -1) printf("탐색 실패 \n");
    else printf("타겟 저장 인덱스 : %d \n", idx);

    idx = ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 2);
    if(idx == -1) printf("탐색 실패 \n");
    else printf("타겟 저장 인덱스 : %d \n", idx);
}