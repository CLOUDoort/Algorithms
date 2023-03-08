#include <stdio.h>
#include "../Chapter 07/ListBaseQueue.h"
#include "../Chapter 07/ListBaseQueue.c"

#define BUCKET_NUM 10

void RadixSort(int arr[], int num, int maxLen) {
    // 매개변수 maxLen에는 정렬대상 중 가장 긴 데이터의 길이 정보가 전달
    Queue buckets[BUCKET_NUM];
    int bi, pos, di, divfac = 1, radix;

    // 총 10개의 bucket 초기화
    for(bi = 0; bi < BUCKET_NUM; bi++) QueueInit(&buckets[bi]);


    // => 시간복잡도는 O(maxlen * num); => 즉 O(n)이라 볼 수 있다. QuickSort보다 빠르지만 적용 가능한 대상이 제한적이라는 단점이 있다.
    // 가장 긴 데이터의 길이만큼 반복
    for(pos = 0; pos < maxLen; pos++) {
        // 정렬대상의 수만큼 반복
        for(di = 0; di < num; di++) {
            // N번째 자리 숫자 추출
            radix = (arr[di] / divfac) % 10;

            // 추출한 숫자를 근거로 버킷에 데이터 저장
            Enqueue(&buckets[radix], arr[di]);
        }

        // 버킷 수만큼 반복
        for(bi = 0, di = 0; bi < BUCKET_NUM; bi++) {
            // 버킷에 저장된 것 순서대로 다 꺼내서 다시 arr에 저장
            while(!QIsEmpty(&buckets[bi])) arr[di++] = Dequeue(&buckets[bi]);
        }
        divfac *= 10;
    }
}

int main(void) {
    int arr[7] = {13, 212, 14, 7141, 10987, 6, 15};
    int len = sizeof(arr)/sizeof(int);
    int i;
    RadixSort(arr, len, 5);
    for(i = 0; i < len; i++) printf("%d ", arr[i]);
}