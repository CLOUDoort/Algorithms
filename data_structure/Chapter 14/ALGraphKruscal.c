#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Chapter 06/ArrayBaseStack.h"
#include "ALGraphKruscal.h"

int WhoIsPrecede(int d1, int d2) {
    if(d1 < d2) return 0;
    else return 1;
}
int PQWeightComp(Edge d1, Edge d2) {
    return d1.weight - d2.weight;
}
void RecoverEdge(ALGraph *pg, int fromV, int toV, int weight) {
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    (pg->numE)++;
}
void RemoveWayEdge(ALGraph *pg, int fromV, int toV) {
    int edge;
    if(LFirst(&(pg->adjList[fromV]), &edge)) {
        if(edge == toV) {
            LRemove(&(pg->adjList[fromV]));
            return;
        }
        while(LNext(&(pg->adjList[fromV]), &edge)) {
            if(edge == toV) {
                LRemove(&(pg->adjList[fromV]));
                return;
            }
        }
    }
}
void RemoveEdge(ALGraph *pg, int fromV, int toV) {
    RemoveWayEdge(pg, fromV, toV);
    RemoveWayEdge(pg, toV, fromV);
    (pg->numE--);
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

    // 우선순위 큐 초기화
    PQueueInit(&(pg->pqueue), PQWeightComp);
}

void GraphDestroy(ALGraph *pg) {
    if(pg->adjList != NULL) free(pg->adjList);
    // 할당된 배열 소멸
    if(pg->visitInfo != NULL) free(pg->visitInfo);
}

// fromV와 toV를 연결하는 간선 추가
void AddEdge(ALGraph *pg, int fromV, int toV, int weight) {
    Edge edge = {fromV, toV, weight};
    // 정점 fromV의 연결리스트에 정점 toV의 정보 추가
    LInsert(&(pg->adjList[fromV]), toV);

    // 정점 toV의 연결리스트에 정점 fromV의 정보 추가
    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;
    
    // 간선의 가중치 정보를 우선순위 큐에 저장
    PEnqueue(&(pg->pqueue), edge);
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

// DFS 기반으로 정의된 함수 : 정점의 정보 출력
void InConnVertex(ALGraph *pg, int v1, int v2) {
    Stack stack;
    int visitV = v1;
    int nextV;

    StackInit(&stack);
    VisitVertex(pg, visitV);
    SPush(&stack, visitV);

    // visitV에 담긴 정점과 연결된 정점의 방문을 시도하는 while문
    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
        int visitFlag = FALSE;
        // 정점 돌아다니다가 목표 찾는다면 TRUE 반환
        if(nextV == v2) {
            memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
            return TRUE;
        }
        if(VisitVertex(pg, nextV) == TRUE) {
            SPush(&stack, visitV);
            visitV = nextV;
            visitFlag = TRUE;
        }
        else {
            while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
                if(nextV == v2) {
                    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
                    return TRUE;
                }
                if(VisitVertex(pg, nextV) == TRUE) {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }
        if(visitFlag == FALSE) {
            if(SIsEmpty(&stack) == TRUE) break;
            else visitV = SPop(&stack);
        }       
    }
    memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
}

void ConKruscalMST(ALGraph *pg) {
    Edge recvEdge[20]; // 복원할 간선의 정보 저장
    Edge edge;
    int eidx = 0;
    int i;

    // MST를 형성할 때까지 while문 반복
    while(pg->numE+1 > pg->numV) {
        // 우선순위 큐에서 가중치가 가장 높은 간선의 정보 꺼낸다.
        edge = PDequeue(&(pg->pqueue));
        // 우선순위 큐에서 꺼낸 간선을 실제로 그래프에서 삭제
        RemoveEdge(pg, edge.v1, edge.v2);

        // 간선을 삭제하고 나서도 두 정점을 연결하는 경로가 있는지 확인한다.
        if(!IsConnVertex(pg, edge.v1, edge.v2)) {
            // 경로가 없다면 삭제한 간선 복원
            RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
            // 복원한 간선의 정보를 별도로 저장
            recvEdge[eidx++] = edge;
        }
    }

    // 우선순위 큐에서 삭제된 간선의 정보를 회복
    for(i = 0; i < eidx; i++) PEnqueue(&(pg->pqueue), recvEdge[i]);
}

void ShowGraphEdgeWeightInfo(ALGraph *pg) {
    PQueue *copyPQ = pg->pqueue;
    Edge edge;

    while(!PQIsEmpty(copyPQ)) {
        edge = PDequeue(copyPQ);
        printf("(%c-%c), w: %d \n", edge.v1+65, edge.v2+65, edge.weight);
    }
}