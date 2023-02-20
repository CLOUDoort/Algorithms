#ifndef __AL_GRAPH_KRUSCAL_H__
#define __AL_GRAPH_KRUSCAL_H__

#include "../Chapter 03, 04, 05/DLinkedList.h"
#include "../Chapter 09/PriorityQueue.h"
#include "ALEdge.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual {
    int numV;
    int numE;
    List *adjList;
    int *visitInfo;
    PQueue *pqueue; // 간선의 가중치 정보 저장
} ALGraph;

// 그래프의 초기화
void GraphInit(ALGraph *pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(ALGraph *pg);

// 간선의 추가
void AddEdge(ALGraph *pg, int fromV, int toV, int weight);

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph *pg);

// 두 정점을 연결
void InConnVertex(ALGraph *pg, int v1, int v2);

// 최소 비용 신창 트리의 구성
void ConKruscalMST(ALGraph *pg);

// 가중치 정보 출력
void ShowGraphEdgeWeightInfo(ALGraph *pg);

#endif