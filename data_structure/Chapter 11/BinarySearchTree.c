#include <stdio.h>
#include "../Chapter 08/BinaryTree2.h"
#include "../Chapter 08/BinaryTree2.c"
#include "BinarySearchTree.h"

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