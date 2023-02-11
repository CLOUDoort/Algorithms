#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree2.h"

// 수식 트리 구성
BTreeNode* MakeExpTree(char exp[]);
// 수식 트리 계산
int EvaluateExpTree(BTreeNode* bt);

// 전위 표기법 출력
void ShowPrefixTypeExp(BTreeNode *bt);
// 중위 표기법 출력
void ShowInfixTypeExp(BTreeNode *bt);
// 후위 표기법 출력
void ShowPostfixTypeExp(BTreeNode *bt);



#endif