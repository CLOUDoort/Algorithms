#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node {
    int data;
    nodePointer leftChild, rightChild;
} node;

nodePointer createNode();
void insertNode(nodePointer *node, int target);
nodePointer modifiedSearch(nodePointer node, int target);
void deleteNode(nodePointer *node, int target);
void inOrderTraversal(nodePointer node);

int main() {
    FILE* fp = fopen("in2.txt", "r");
    if(fp == NULL) {
        printf("file read error\n");
        exit(1);
    }
    nodePointer root = NULL;
    int n = 0; fscanf(fp, "%d", &n);
    int data = 0;
    while(n--) {
        fscanf(fp, "%d", &data);
        insertNode(&root, data);
    }
    int delCnt = 0;
    fscanf(fp, "%d", &delCnt);
    while(delCnt--) {
        fscanf(fp, "%d", &data);
        deleteNode(&root, data);
    }
    inOrderTraversal(root);
    fclose(fp);
    return 0;
}

void insertNode(nodePointer *node, int target) {
    nodePointer ptr, temp = modifiedSearch(*node, target);
    if(temp || !(*node)) {
        ptr = createNode();
        ptr->data = target;
        ptr->leftChild = ptr->rightChild = NULL;
        if(*node) {
            if(target < temp->data) temp->leftChild = ptr;
            else temp->rightChild = ptr;
        }
        else *node = ptr;
    }
}

nodePointer modifiedSearch(nodePointer node, int target) {
    if(!node) return NULL;
    else {
        while(node) {
            if(node->data == target) return NULL;
            else if(node->data > target) {
                if(!(node->leftChild)) return node;
                node = node->leftChild;
            }
            else {
                if(!(node->rightChild)) return node;
                node = node->rightChild;
            }
        }
    }
    return NULL;
}

void deleteNode(nodePointer *node, int target) {
    nodePointer delNode, maxLeft;
    if(!(*node)) {
        printf("E ");
        return;
    }
    else {
        if((*node)->data == target) {
            // 단말노드
            if(!(*node)->leftChild && !(*node)->rightChild) {
                free(*node);
                printf("S "); return;
            }
            else if(!(*node)->rightChild) {
                delNode = *node;
                *node = (*node)->leftChild;
                free(delNode); printf("S "); return;
            }
            else if(!(*node)->leftChild) {
                delNode = *node;
                *node = (*node)->rightChild;
                free(delNode); printf("S "); return;
            }
            else {
                maxLeft = (*node)->leftChild;
                while(maxLeft->rightChild) {
                    maxLeft = maxLeft->rightChild;
                }
                (*node)->data = maxLeft->data;
                deleteNode(&maxLeft, maxLeft->data);
            }
        }
        else if((*node)->data > target) deleteNode(&((*node)->leftChild), target);
        else deleteNode(&((*node)->rightChild), target);
    }
}

void inOrderTraversal(nodePointer node) {
    if(node) {
        inOrderTraversal(node->leftChild);
        printf("%d ", node->data);
        inOrderTraversal(node->rightChild);
    }
}

nodePointer createNode() {
    nodePointer newNode = (nodePointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    return newNode;
}