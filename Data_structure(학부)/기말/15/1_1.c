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
void inOrderTraversal(treePointer node);
void eraseNode(treePointer *node);

int main() {
    FILE* fp = fopen("in.txt", "r");
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

treePointer modifiedSearch(treePointer node, int target) {
    if(!node) return NULL;
    while(node) {
        if(target == node->key) return NULL;
        else if(target < node->key) {
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
        } else {
            *node = ptr;
        }
    }
}

void inOrderTraversal(treePointer node) {
    if(node) {
        inOrderTraversal(node->leftChild);
        printf("%d ", node->key);
        inOrderTraversal(node->rightChild);
    }
}

void eraseNode(treePointer *node) {
    treePointer delNode;
    delNode = *node;
    if(*node) { 
        eraseNode(&(delNode->leftChild));
        eraseNode(&(delNode->rightChild));
        free(delNode);
    }
}

treePointer createNode() {
    treePointer newNode = (treePointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}