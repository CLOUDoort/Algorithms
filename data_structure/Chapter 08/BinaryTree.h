#ifndef __BINARY_TREE__
#define __BINARY_TREE__

typedef int BTData;

typedef struct _bTreeNode {
    BTData data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
} BTreeNode;

// 노드 생성
BTreeNode* MakeBTreeNode(void);
// 노드에 저장된 데이터 반환
BTData GetData(BTreeNode *bt);
// 노드에 데이터 저장
void SetData(BTreeNode *bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode *bt);
BTreeNode* GetRightSubTree(BTreeNode *bt);

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);

#endif