/*
- matrixNode와 matrixPointer 선언해준다.
- newNode 함수 생성한다.
- 메뉴판 만들고 mread 함수를 통해 데이터 입력받고 mwrite 함수를 통해서 출력한다.
- node 해제하는 erase 함수 만든다.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

typedef enum { head, entry } tagfield;

typedef struct matrixNode* matrixPointer;
typedef struct entryNode {
	int row;
	int col;
	int value;
}entryNode;
typedef struct matrixNode {
	matrixPointer down;
	matrixPointer right;
	tagfield tag;
	union {
		matrixPointer next;
		entryNode entry;
	}u;
}matrixNode;
matrixPointer hdNode[MAX_SIZE];

matrixPointer mread();
matrixPointer newNode();
void mwrite(matrixPointer node);
void merase(matrixPointer* node);

int main() {
	int a = 0;
	matrixPointer node = NULL;
	while (1) {
		printf("matrix 작업 선택 (1.입력 2.출력 3.삭제 4.종료): ");
		scanf("%d", &a);
		if (a == 4) break;
		else if (a == 1) node = mread();
		else if (a == 2) mwrite(node);
		else if (a == 3) merase(&node);
	}
	return 0;
}

matrixPointer mread() {
	int numRows, numCols, numTerms, numHeads;
	int row, col, value, currentRow;
	matrixPointer node, temp, last;
	printf("행과 열의 크기 및 nonzero 항의 개수 입력\n");
	scanf("%d %d %d", &numRows, &numCols, &numTerms);
	numHeads = (numCols > numRows) ? numCols : numRows;
	node = newNode(); node->tag = entry;
	node->u.entry.row = numRows; node->u.entry.col = numCols;
	if (!numHeads) node->right = node;
	else {
		for (int i = 0; i < numHeads; i++) {
			temp = newNode();
			hdNode[i] = temp;
			hdNode[i]->tag = head;
			hdNode[i]->right = temp;
			hdNode[i]->u.next = temp;
		}
		currentRow = 0; last = hdNode[0];
		printf("행, 열, 값 입력\n");
		for (int i = 0; i < numTerms; i++) {
			scanf("%d %d %d", &row, &col, &value);
			if (row > currentRow) {
				last->right = hdNode[currentRow];
				currentRow = row;
				last = hdNode[row];
			}
			temp = newNode();
			temp->tag = entry;
			temp->u.entry.row = row; temp->u.entry.col = col;
			temp->u.entry.value = value;

			last->right = temp; last = temp;
			hdNode[col]->u.next->down = temp;
			hdNode[col]->u.next = temp;
		}
		last->right = hdNode[currentRow];

		for (int i = 0; i < numCols; i++) {
			hdNode[i]->u.next->down = hdNode[i];
		}
		for (int i = 0; i < numHeads - 1; i++) {
			hdNode[i]->u.next = hdNode[i + 1];
		}
		hdNode[numHeads - 1]->u.next = node;
		node->right = hdNode[0];
	}
	return node;
}

void mwrite(matrixPointer node) {
	matrixPointer temp, head = node->right;
	printf("\n numRows = %d, numCols = %d\n", node->u.entry.row, node->u.entry.col);
	printf("The matrix by row, column, and value: \n\n");
	for (int i = 0; i < node->u.entry.row; i++) {
		for (temp = head->right; temp != head; temp = temp->right) {
			printf("%5d%5d%5d\n\n", temp->u.entry.row, temp->u.entry.col, temp->u.entry.value);
		}
		head = head->u.next;
	}
}

void merase(matrixPointer* node) {
	matrixPointer x, y, head = (*node)->right;
	for (int i = 0; i < (*node)->u.entry.row; i++) {
		y = head->right;
		while (y != head) {
			x = y; y = y->right; free(x);
		}
		x = head; head = head->u.next; free(x);
	}
	y = head;
	while (y != *node) {
		x = y; y = y->u.next; free(x);
	}
	free(*node); *node = NULL;
}


matrixPointer newNode() {
	matrixPointer newNode = (matrixPointer)malloc(sizeof(*newNode));
	if (newNode == NULL) {
		printf("malloc error\n");
		exit(1);
	}
	return newNode;
}