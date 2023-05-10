/*
- 파일을 읽고 insert한다.
- insert할 때 modifiedSearch 함수를 통해 어디에 insert할 지 탐색한다.
- tree 구성하고 inOrderTraversal해준다.
- node를 erase 한다.
- 파일 닫는다.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct node {
    int key;
    treePointer leftChild, rightChild;
} node;

treePointer createNode();
void insert(treePointer *node, int target);
treePointer modifiedSearch(treePointer node, int target);
void inOrderTraversal(treePointer root);
void eraseNode(treePointer *root);

int main() {
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("File read error\n");
        exit(1);
    }
    treePointer root = NULL;
    int value = 0;
    while(fscanf(fp, "%d", &value) != EOF) insert(&root, value);
    inOrderTraversal(root);
    eraseNode(&root);
    fclose(fp);
    return 0;
}

// tree is empty or target is present return NULL
// else return a pointer(to the last node)
treePointer modifiedSearch(treePointer node, int target) {
    if(!node) return NULL;
    while(node) {
        if(target == node->key) return NULL;
        if(target < node->key) {
            if(!(node->leftChild)) return node;
            node = node->leftChild;
        }
        else {
            if(!(node->rightChild)) return node;
            node = node->rightChild;
        }
    }
    return NULL;
}

void insert(treePointer *node, int target) {
    treePointer ptr, temp = modifiedSearch(*node, target);
    if(temp || !(*node)) {
        ptr = createNode();
        ptr->key = target;
        if(*node) {
            if(target < temp->key) temp->leftChild = ptr;
            else temp->rightChild = ptr;
        }
        else *node = ptr;
    }
}

void inOrderTraversal(treePointer node) {
    if(node) {
        inOrderTraversal(node->leftChild);
        printf("%d ", node->key);
        inOrderTraversal(node->rightChild);
    }
}

void eraseNode(treePointer *root) {
    treePointer delNode;
    delNode = *root;
    if(*root) {
        eraseNode(&(delNode->leftChild));
        free(delNode);
        eraseNode(&(delNode->rightChild));
    }
}

treePointer createNode() {
    treePointer newNode = (treePointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("Malloc error\n");
        exit(1);
    }
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    return newNode;
}