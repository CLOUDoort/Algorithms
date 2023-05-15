/*
- 파일로부터 데이터 입력받아 이진탐색트리를 만든다.
- 파일로부터 삭제할 데이터 입력받아 삭제한다.
    - 서브트리가 없는 경우
        - 단순하게 삭제할 노드 바로 free해준다.
    - 왼쪽 서브트리, 또는 오른쪽 서브트리가 있는 경우
        - 삭제할 노드와 삭제할 노드의 Parent node를 찾는다.
        - 삭제할 노드가 root노드일 경우와 아닌 경우를 나눠준다.
        - parent노드와 삭제할 노드의 데이터 크기 비교해서 적절하게 옮겨준다.
    - 왼쪽 서브트리와 오른쪽 서브트리가 모두 있는 경우
        - 왼쪽 서브 트리 중에서 가장 큰 값을 찾아 replace하고 삭제하거나 오른쪽 서브트리의 가장 작은 값을 찾아 replace하고 삭제한다.
- inOrderTraversal한다.
- 메모리 해제한다.
- 파일닫는다.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct node {
    int data;
    treePointer left, right;
} node;

treePointer createNode();
void insert(treePointer *node, int target);
treePointer modifiedSearch(treePointer node, int target);
void deleteNode(treePointer *node, int target);
void inOrderTraversal(treePointer node);
void eraseNode(treePointer *node);
treePointer delNodeSearch(treePointer node, int target);
treePointer delParentSearch(treePointer node, int target);

int main() {
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("File read error\n");
        exit(1);
    }
    treePointer root = NULL;
    int n = 0;
    fscanf(fp, "%d", &n);
    int value = 0;
    while(n--) {
        fscanf(fp, "%d", &value);
        insert(&root, value);
    }
    int deleteCount = 0;
    fscanf(fp, "%d", &deleteCount);
    int delTarget = 0;
    while(deleteCount--) {
        fscanf(fp, "%d", &delTarget);
        deleteNode(&root, delTarget);
    }
    inOrderTraversal(root);
    eraseNode(&root);
    fclose(fp);
    return 0;
}

void deleteNode(treePointer *node, int target) {
    treePointer delNode = delNodeSearch(*node, target);
    treePointer parent = delParentSearch(*node, target);
    if(delNode) {
        if(!(delNode->left) && !(delNode->right)) {
            free(delNode);
            printf("S ");
            return;
        }
        else if(delNode->left && !(delNode->right)) {
            if(parent == NULL) {
                *node = delNode->left;
            }
            else {
                if(delNode->data > parent->data) {
                    parent->right = delNode->left;
                }
                else parent->left = delNode->left;
            }
            free(delNode);
            printf("S ");
            return;
        }
        else if(delNode->right && !(delNode->left)) {
            if(parent == NULL) {
                *node = delNode->right;
            }
            else {
                if(delNode->data > parent->data) {
                    parent->right = delNode->right;
                }
                else parent->left = delNode->right;
            }
            free(delNode);
            printf("S ");
            return;
        }
        else {
            // 왼쪽 서브트리에서 가장 큰 값 찾기
            treePointer searchNode = delNode;
            treePointer replaceNode = delNode;
            searchNode = searchNode->left;
            while(searchNode) {
                replaceNode = searchNode;
                searchNode = searchNode->right;
            }
            delNode->data = replaceNode->data;
            deleteNode(&(replaceNode), replaceNode->data);
        }
    }
    else {
        printf("E ");
        return;
    }
}

treePointer delParentSearch(treePointer node, int target) {
    if(!node) return NULL;
    treePointer parent = NULL;
    while(node) {
        if(target == node->data) {
            return parent;
        }
        else if(target < node->data) {
            parent = node;
            node = node->left;
        }
        else {
            parent = node;
            node = node->right;
        }
    }
    return NULL;
}

treePointer delNodeSearch(treePointer node, int target) {
    if(!node) return NULL;
    while(node) {
        if(target == node->data) return node;
        else if(target < node->data) node = node->left;
        else node = node->right;
    }
    return NULL;
}

treePointer modifiedSearch(treePointer node, int target) {
    if(!node) return NULL;
    while(node) {
        if(target == node->data) return NULL;
        else if(target < node->data) {
            if(!(node->left)) return node;
            else node = node->left;
        }
        else {
            if(!(node->right)) return node;
            else node = node->right;
        }
    }
    return NULL;
}

void insert(treePointer *node, int target) {
    treePointer ptr, temp = modifiedSearch(*node, target);
    if(temp || !(*node)) {
        ptr = createNode();
        ptr->data = target;
        if(*node) {
            if(target < temp->data) temp->left = ptr;
            else temp->right = ptr;
        }   
        else *node = ptr;
    }
}

void inOrderTraversal(treePointer node) {
    if(node) {
        inOrderTraversal(node->left);
        if(node->data) printf("%d ", node->data);
        inOrderTraversal(node->right);
    }
}

void eraseNode(treePointer *node) {
    treePointer delNode;
    if(*node) {
        delNode = *node;
        eraseNode(&(delNode->left));
        free(delNode);
        eraseNode(&(delNode->right));
    }
}

treePointer createNode() {
    treePointer newNode = (treePointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("Malloc error\n");
        exit(1);
    }
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}