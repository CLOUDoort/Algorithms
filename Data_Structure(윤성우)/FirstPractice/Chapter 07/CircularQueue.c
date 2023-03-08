#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

// 텅 빈 경우 front와 rear 위치 동일
void QueueInit(Queue *pq) {
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue *pq) {
    if(pq->front == pq->rear) return TRUE;
    else return FALSE;
}

int NextPosIdx(int pos) {
    // 배열의 마지막 요소의 인덱스 값이라면 앞으로 이동해야 함을 의미
    if(pos == QUE_LEN - 1) return 0;
    else return pos+1;
}

void Enqueue(Queue *pq, Data data) {
    if(NextPosIdx(pq->rear) == pq->front) {
        printf("Queue Memory Error!");
        exit(-1);
    }
    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue *pq) {
    if(QIsEmpty(pq)) {
        printf("Queue Memory Error!\n");
        exit(-1);
    }
    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}

Data Qpeek(Queue *pq) {
    if(QIsEmpty(pq)) {
        printf("Queue Memory Error\n");
        exit(-1);
    }
    return pq->queArr[NextPosIdx(pq->front)];
}