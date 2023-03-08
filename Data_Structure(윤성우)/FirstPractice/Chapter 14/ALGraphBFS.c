#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Chapter 07/CircularQueue.h"
#include "ALGraphBFS.h"

int WhoIsPrecede(int d1, int d2) {
    if(d1 < d2) return 0;
    else return 1;
}

void GraphInit(ALGraph *pg, int nv) {
    pg->numV = nv;
    pg->numE = 0;

    // 정점의 수에 해당하는 길이의 리스트 배열을 생성한다.
    pg->adjList = (List*)malloc(sizeof(List)*nv);

    // 정점의 수만큼 생성된 리스트들 초기화
    for(int i = 0; i < nv; i++) {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }

    // 정점의 수를 길이로 하여 배열 할당
    pg->visitInfo = (int*)malloc(sizeof(int)*pg->numV);
    // 배열의 모든 요소를 0으로 초기화
    memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
}

void GraphDestroy(ALGraph *pg) {
    if(pg->adjList != NULL) free(pg->adjList);
    // 할당된 배열 소멸
    if(pg->visitInfo != NULL) free(pg->visitInfo);
}

// fromV와 toV를 연결하는 간선 추가
void AddEdge(ALGraph *pg, int fromV, int toV) {
    // 정점 fromV의 연결리스트에 정점 toV의 정보 추가
    LInsert(&(pg->adjList[fromV]), toV);

    // 정점 toV의 연결리스트에 정점 fromV의 정보 추가
    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph *pg) {
    int vx;
    for(int i = 0; i < pg->numV; i++) {
        printf("%c와 연결된 정점: ", i+65);
        if(LFirst(&(pg->adjList[i]), &vx)) {
            printf("%c ", vx+65);
            while(LNext(&(pg->adjList[i]), &vx)) {
                printf("%c ", vx+65);
            }
        }
        printf("\n");
    }
}

int VisitVertex(ALGraph *pg, int visitV) {
    // 두 번째 매개변수로 전달된 이름의 정점 방문
    // 방문한적이 없다면
    if(pg->visitInfo[visitV] == 0) {
        pg->visitInfo[visitV] = 1;
        printf("%c ", visitV+65);
        return TRUE;
    }
    return FALSE;
}

// BFS 기반으로 정의된 함수 : 정점의 정보 출력
void BFShowGraphVertex(ALGraph *pg, int startV) {
    Queue queue;
    int visitV = startV;
    int nextV;

    QueueInit(&queue);
    VisitVertex(pg, visitV);
    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
        if(VisitVertex(pg, nextV) == TRUE) Enqueue(&queue, nextV);
        while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
            if(VisitVertex(pg, nextV) == TRUE) Enqueue(&queue, nextV);
        }
        if(QIsEmpty(&queue) == TRUE) break;
        else visitV = Dequeue(&queue);
    }
    memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
}