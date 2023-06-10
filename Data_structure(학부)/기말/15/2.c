/*
- 파일로부터 level order traversal 출력 데이터 받아서 트리 그리고 이를 완전이진트리로 구성한다.
- 구성한 이진트리를 inOrder traversal한다.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 22
#define TREE_FULL(n) (n == MAX_ELEMENTS-1)

typedef struct element {
    char data;
} element;
int n = 0;

element tree[MAX_ELEMENTS];

void push(element data);
void inOrderTraversal(int i);

int main() {
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("FILE read error\n");
        exit(1);
    }
    int cnt = 0;
    fscanf(fp, "%d", &cnt);
    element newElement; char data;
    while(cnt--) {
        fscanf(fp, " %c", &newElement.data);
        push(newElement);
    }
    inOrderTraversal(1);
    fclose(fp);
    return 0;
}

void push(element data) {
    if(TREE_FULL(n)) {
        printf("Tree full\n");
        exit(1);
    }
    tree[++n] = data;
}

void inOrderTraversal(int i) {
    if(i*2 <= n) inOrderTraversal(i*2);
    printf("%c ", tree[i].data);
    if(i*2+1 <= n) inOrderTraversal(i*2+1);

}