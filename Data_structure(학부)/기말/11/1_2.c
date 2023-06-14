#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50
typedef enum { head, entry } tagField;
typedef struct matrixNode* matrixPointer;
typedef struct entryNode {
    int row;
    int col;
    int value;
} entryNode;
typedef struct matrixNode {
    matrixPointer down;
    matrixPointer right;
    tagField tag;
    union {
        matrixPointer next;
        entryNode entry;
    } u;
} matrixNode;
matrixPointer hdNode[MAX_SIZE];

matrixPointer createNode();
matrixPointer mread();
void mwrite(matrixPointer node);
void merase(matrixPointer *node);

int main() {
    int a = 0;
    matrixPointer root = NULL;
    while(1) {
        printf("matrix 작업 선택 (1.입력 2.출력 3.삭제 4.종료): ");
        scanf("%d", &a);
        if(a == 4) break;
        else if(a == 1) root = mread();
        else if(a == 2) mwrite(root);
        else if(a == 3) merase(&root);
    }
    return 0;
}

void merase(matrixPointer *node) {
    matrixPointer x, y, head = (*node)->right;
    int i, numHeads;
    for(i = 0; i < (*node)->u.entry.row; i++) {
        y = head->right;
        while(y != head) {
            x = y; y = y->right; free(x);
        }
        x = head; head = head->u.next; free(x);
    }
    y = head;
    while(y != head) {
        x = y; y = y->u.next; free(x);
    }
    free(*node); *node = NULL;
}

void mwrite(matrixPointer node) {
    int i;
    matrixPointer temp, head = node->right;
    printf("\n numRows = %d, numCols = %d\n", node->u.entry.row, node->u.entry.col);
    printf("The matrix by row, column, and value: \n\n");
    for(i = 0; i < node->u.entry.row; i++) {
        for(temp = head->right; temp != head; temp = temp->right) {
            printf("%5d%5d%5d\n", temp->u.entry.row, temp->u.entry.col, temp->u.entry.value);
        }
        head = head->u.next;
    }
}


matrixPointer mread() {
    int numRows, numCols, numTerms, numHeads, i;
    int row, col, value, currentRow;
    matrixPointer temp, last, node;

    printf("행과 열의 크기 및 nonzero 항의 개수 입력\n");
    scanf("%d %d %d", &numRows, &numCols, &numTerms);
    numHeads = (numCols > numRows) ? numCols : numRows;
    node = createNode(); node->tag = entry;
    node->u.entry.row = numRows; node->u.entry.col = numCols;
    if(!numHeads) node->right = node;
    else {
        for(int i = 0; i < numHeads; i++) {
            temp = createNode();
            hdNode[i] = temp;
            hdNode[i]->tag = head;
            hdNode[i]->right = temp;
            hdNode[i]->u.next = temp;
        }
        currentRow = 0;
        last = hdNode[0];
        printf("행, 열, 값 입력\n");
        for(i = 0; i < numTerms; i++) {
            scanf("%d%d%d", &row, &col, &value);
            if(row > currentRow) {
                last->right = hdNode[currentRow];
                currentRow = row;
                last = hdNode[row];
            }
            temp = createNode();
            temp->tag = entry;
            temp->u.entry.row = row; temp->u.entry.col = col;
            temp->u.entry.value = value;

            last->right = temp;
            last = temp;
            hdNode[col]->u.next->down = temp;
            hdNode[col]->u.next = temp;
        }
        last->right = hdNode[currentRow];
        for(i = 0; i < numCols; i++) {
            hdNode[i]->u.next->down = hdNode[i];
        }
        for(i = 0; i < numHeads; i++) {
            hdNode[i]->u.next = hdNode[i+1];
        }
        hdNode[numHeads-1]->u.next = node;
        node->right = hdNode[0];
    }
    return node;
}

matrixPointer createNode() {
    matrixPointer newNode = (matrixPointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    return newNode;
}