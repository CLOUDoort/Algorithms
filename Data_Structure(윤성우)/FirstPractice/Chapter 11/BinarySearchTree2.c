#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree2.h"

void BSTMakeAndInit(BTreeNode **pRoot) {
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode *bst) {
    return GetData(bst);
}

void BSTInsert(BTreeNode **pRoot, BSTData data) {
    BTreeNode *pNode = NULL; // parent node
    BTreeNode *cNode = *pRoot; // current node
    BTreeNode *nNode = NULL; // new node

    // new node 추가할 위치 찾기
    while(cNode != NULL) {
        // 데이터(key)의 중복 허락하지 않음
        if(data == GetData(cNode)) return;

        pNode = cNode;

        if(GetData(cNode) > data) cNode = GetLeftSubTree(cNode);
        else cNode = GetRightSubTree(cNode);
    }

    // new node 생성하기
    nNode = MakeBTreeNode();
    SetData(nNode, data);

    // pNode의 자식 node로 추가
    if(pNode != NULL) {
        if(data < GetData(pNode)) MakeLeftSubTree(pNode, nNode);
        else MakeRightSubTree(pNode, nNode);
    }
    // new node가 root node라면
    else {
        *pRoot = nNode;
    }
}

BTreeNode* BSTSearch(BTreeNode *bst, BSTData target) {
    BTreeNode *cNode = bst;
    BSTData cd;

    while(cNode != NULL) {
        cd = GetData(cNode);
        if(target == cd) return cNode;
        else if(target < cd) cNode = GetLeftSubTree(cNode);
        else cNode = GetRightSubTree(cNode);
    }
    // 탐색대상 없음
    return NULL;
}

BTreeNode* BSTRemove(BTreeNode **pRoot, BSTData target) {
    // 삭제 대상이 루트 노드인 경우를 별도로 고려해야 한다.
    BTreeNode *pVRoot = MakeBTreeNode(); // 가상 루트 노드
    BTreeNode *pNode = pVRoot; // parent node
    BTreeNode *cNode = *pRoot; // current node
    BTreeNode *dNode; // delete node

    // 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 자식 노드로 지정
    ChangeRightSubTree(pVRoot, *pRoot);

    // 삭제 대상인 노드를 탐색
    while(cNode != NULL && GetData(cNode) != target) {
        pNode = cNode;
        if(target < GetData(cNode)) cNode = GetLeftSubTree(cNode);
        else cNode = GetRightSubTree(cNode);
    }

    // 삭제 대상이 없을 경우
    if(cNode == NULL) return NULL;

    dNode = cNode;

    // 첫 번째 경우 : 삭제 대상이 단말 노드인 경우
    if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
        if(GetLeftSubTree(pNode) == dNode) RemoveLeftSubTree(pNode);
        else RemoveRightSubTree(pNode);
    }
    // 두 번째 경우 : 삭제 대상이 하나의 자식 노드를 갖는 경우
    else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {
        // 삭제 대상의 자식 노드 가리킴
        BTreeNode *dcNode;
        if(GetLeftSubTree(dNode) != NULL) dcNode = GetLeftSubTree(dNode);
        else dcNode = GetRightSubTree(dNode);

        if(GetLeftSubTree(pNode) == dNode) ChangeLeftSubTree(pNode, dcNode);
        else ChangeRightSubTree(pNode, dcNode);
    }
    // 세 번째 경우 : 두 개의 자식 노드를 모두 갖는 경우
    // 삭제할 노드의 오른쪽 서브 트리에서 가장 작은 값을 지니는 노드를 찾아서 삭제할 노드를 대체한다.
    else {
        // 대체 노드를 가리킴 = 삭제할 노드의 오른쪽 서브 트리
        BTreeNode *mNode = GetRightSubTree(dNode);
        // 대체노드의 부모노드를 가리킴
        BTreeNode *mpNode = dNode;
        int delData;

        // 삭제 대상의 대체 노드를 찾는다. 가장 작은 값 찾으니까 왼쪽 서브트리에서 찾는다.
        while(GetLeftSubTree(mNode) != NULL) {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }

        // 대체 노드에 저장된 값을 삭제할 노드에 대입한다.
        delData = GetData(dNode);
        SetData(dNode, GetData(mNode));

        // 대체 노드의 부모노드와 자식 노드를 연결한다.
        if(GetLeftSubTree(mpNode) == mNode) ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
        else ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

        dNode = mNode;
        SetData(dNode, delData);
    }

    // 삭제된 노드가 루트 노드인 경우 추가 처리
    if(GetRightSubTree(pVRoot) != *pRoot) *pRoot = GetRightSubTree(pVRoot);

    free(pVRoot);
    return dNode;
}

void ShowIntData(int data) { 
    printf("%d ", data); 
}

void BSTShowAll(BTreeNode *bst) {
    InorderTraverse(bst, ShowIntData);
}