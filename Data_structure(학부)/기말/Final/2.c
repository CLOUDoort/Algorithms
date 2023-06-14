//  2017116145-강준석
#include <stdio.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
} node;

treePointer createNode();
void init(treePointer *root);
void insertNode(treePointer *root, int data);
void deleteNode(treePointer *root, int target);
void searchNode(treePointer root, int target);
treePointer modifiedSearch(treePointer root, int target);
void inOrderTraversal(treePointer root);

int main() {
    int a = 0, data = 0;
    treePointer root = NULL;
    init(&root);
    while(1) {
        printf("BST (1.insert 2.delete 3.search 4.output 5.exit) : ");
        scanf("%d", &a);
        printf("\n");
        if(a == 1) {
            printf("insert> "); scanf("%d", &data);
            insertNode(&root, data);
            inOrderTraversal(root);
        }
        else if(a == 2) {
            printf("delete> "); scanf("%d", &data);
            deleteNode(&root, data);
            inOrderTraversal(root);
        }
        else if(a == 3) {
            printf("search> "); scanf("%d", &data);
            searchNode(root, data);
        }
        else if(a == 4) inOrderTraversal(root);
        else if(a == 5) break;
        printf("\n\n");
    }
    return 0;
}

treePointer modifiedSearch(treePointer root, int target) {
    if(!root) return NULL;
    else {
        while(root) {
            if(root->data == target) return NULL;
            else if(root->data > target) {
                if(!(root->leftChild)) return root;
                root = root->leftChild;
            }
            else {
                if(!(root->rightChild)) return root;
                root = root->rightChild;
            }
        }
    }
    return NULL;
}

void insertNode(treePointer *root, int data) {
    treePointer ptr, temp = modifiedSearch(*root, data);
    if(temp || !(*root)) {
        ptr = createNode();
        ptr->data = data;
        if(*root) {
            if(data < temp->data) temp->leftChild = ptr;
            else temp->rightChild = ptr;
        }
        else {
            *root = ptr;
        }
    }
}

void deleteNode(treePointer *root, int target) {
    if(*root) {
        if((*root)->data == target) {
            // 단말노드
            if(!((*root)->leftChild) && !((*root)->rightChild)) {
                free(*root); *root = NULL;
            }
            // left
            else if(!((*root)->rightChild)) {
                treePointer delNode = *root;
                *root = (*root)->leftChild;
                free(delNode);
            }
            // right
            else if(!((*root)->leftChild)) {
                treePointer delNode = *root;
                *root = (*root)->rightChild;
                free(delNode);
            }
            // 둘 다 있을 때, 왼쪽에서 가장 큰 값
            else {
                treePointer maxLeft = (*root)->leftChild;
                while(maxLeft->rightChild) {
                    maxLeft = maxLeft->rightChild;
                }
                (*root)->data = maxLeft->data;
                deleteNode(&maxLeft, maxLeft->data);
            }
        }
        else if((*root)->data > target) deleteNode(&((*root)->leftChild), target);
        else deleteNode(&((*root)->rightChild), target);
    }
}

void searchNode(treePointer root, int target) {
    if(root) {
        while(root) {
            if(root->data == target) {
                printf("S");
                return;
            }
            else if(root->data > target) {
                root = root->leftChild;
            }
            else root = root->rightChild;
        }
    }
    printf("E");
}

void init(treePointer *root) {
    FILE* fp = fopen("in2.txt", "r");
    if(fp == NULL) {
        printf("file read error\n");
        exit(1);
    }
    int data;
    while(fscanf(fp, "%d", &data) != EOF) {
        insertNode(root, data);
    }
    fclose(fp);
}

void inOrderTraversal(treePointer root) {
    if(root) {
        inOrderTraversal(root->leftChild);
        if(root->data) printf("%d ", root->data);
        inOrderTraversal(root->rightChild);
    }
}

treePointer createNode() {
    treePointer newNode = (treePointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    newNode->leftChild = newNode->rightChild = NULL;
    return newNode;
}