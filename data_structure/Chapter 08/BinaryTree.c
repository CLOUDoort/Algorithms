#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode* MakeBTreeNode(void) {
    BTreeNode *nd = (BTreeNode*)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

BTData GetData(BTreeNode *bt) {
    return bt->data;
}

void SetData(BTreeNode *bt, BTData data) {
    bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode *bt) {
    return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode *bt) {
    return bt->right;
}


// 왼쪽 또는 오른쪽 서브 트리가 존재한다면, 해당 트리를 삭제하고서 새로운 서브트리를 연결
// 삭제할 서브 트리가 하나의 노드르오 이루어져 있다면 문제가 없지만, 두 개 이상의 노드로 이루어져 있다면 순회가 불가피하다.
void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub) {
    if(main->left != NULL) free(main->right);
    main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub) {
    if(main->right != NULL) free(main->right);
    main->right = sub;
}