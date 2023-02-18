#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"

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
}

void GraphDestroy(ALGraph *pg) {
    if(pg->adjList != NULL) free(pg->adjList);
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