// 이진 트리에 데이터의 저장 규칙을 더해놓은 것이 이진 탐색 트리이다.
// 작으면 왼쪽으로 크면 오른쪽으로 저장
// 탐색은 이와 같은 방법으로 비교대상보다 작으면 왼쪽 노드, 크면 오른쪽 노드로 이동
// 때문에 이진 탐색 트리는 탐색 과정에서 길을 잃을 일이 없다.
#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "../Chapter 08/BinaryTree2.h"

typedef BTData BSTData;

// BST의 생성 및 초기화
void BSTMakeAndInit(BTreeNode **pRoot);

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode *bst);

// BST를 대상으로 데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode **pRoot, BSTData data);

// BST를 대상으로 데이터 탐색
BTreeNode* BSTSearch(BTreeNode *bst, BSTData target);

#endif