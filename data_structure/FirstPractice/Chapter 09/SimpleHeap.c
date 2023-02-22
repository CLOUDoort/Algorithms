/*
- 힙은 완전 이진 트리이다.
- 힙의 구현은 배열을 기반으로 하며 인덱스가 0인 요소는 비워둔다.
- 따라서 힙의 구현은 저장된 노드의 개수와 마지막 노드의 고유번호는 일치한다.
- 노드의 고유번호가 노드가 저장되는 배열의 인덱스 값이 된다.
- 우선순위를 나타내는 정수 값이 작을수록 높은 우선순위를 나타낸다고 가정한다.
*/
#include "SimpleHeap.h"

// 힙 초기화
void HeapInit(Heap *ph) {
    ph->numOfData = 0;
}

int HIsEmpty(Heap *ph) {
    if(ph->numOfData == 0) return TRUE;
    else return FALSE;
}

int GetParentIDX(int idx) {
    return idx/2;
}
int GetLChildIDX(int idx) {
    return idx*2;
}
int GetRChildIDX(int idx) {
    return GetLChildIDX(idx)+1;
}

// 두 개의 자식 노드 중 높은 우선순위를 가진 자식 노드 인덱스 값 반환
int GetHiPriChildIDX(Heap *ph, int idx) {
    // 노드가 없는 상황
    if(GetLChildIDX(idx) > ph->numOfData) return 0;
    // 왼쪽 자식 노드밖에 없는 상황
    else if(GetLChildIDX(idx) == ph->numOfData) return GetLChildIDX(idx);
    // 왼쪽, 오른쪽 노드 둘 다 있는 상황
    else {
        if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr) return GetRChildIDX(idx);
        else return GetLChildIDX(idx);
    }
}

// 힙에 데이터 저장
void HInsert(Heap *ph, HData data, Priority pr) {
    int idx = ph->numOfData+1;
    HeapElem nelm = {pr, data};
    
    while(idx != 1) {
        if(pr < (ph->heapArr[GetParentIDX(idx)].pr)) {
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else break;
    }
    ph->heapArr[idx] = nelm;
    ph->numOfData += 1;
}

// 힙에서 데이터 삭제
// 루트 노드 삭제하고 제일 마지막 노드를 루트노드로 올린 뒤 비교
HData HDelete(Heap *ph) {
    // 삭제할 루트 노드
    HData delData = (ph->heapArr[1]).data;
    // 힙의 마지막 노드
    HeapElem lastElem = ph->heapArr[ph->numOfData];

    // parentIdx는 마지막 노드가 저장될 위치정보다 담긴다.
    int parentIdx = 1;
    int childIdx;

    while((childIdx = GetHiPriChildIDX(ph, parentIdx))) {
        // 마지막 노드의 우선순위가 루트의 우선순위가 높은 자식노드의 우선순위보다 높다면 break;
        if(lastElem.pr <= ph->heapArr[childIdx].pr) break;
        
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }
    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return delData;
}