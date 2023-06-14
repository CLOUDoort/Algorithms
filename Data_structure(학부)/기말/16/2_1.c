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
    if(!(*node)) {
        printf("E ");
        return;
    }
    if((*node)->data > target) deleteNode(&((*node)->left), target);
    else if((*node)->data < target) deleteNode(&((*node)->right), target);
    else {
        if(!((*node)->left) && !((*node)->right)) {
            free(*node);
            printf("S ");
            return;
        }
        else if(!((*node)->left)) {
            treePointer temp = *node;
            *node = (*node)->right;
            free(temp);
            printf("S "); return;
        }
        else if(!((*node)->right)) {
            treePointer temp = *node;
            *node = (*node)->left;
            free(temp); printf("S "); return;
        }
        else {
            treePointer minLeft = (*node)->left;
            while(minLeft->right) {
                minLeft = minLeft->right;
            }
            (*node)->data = minLeft->data;
            deleteNode(&(minLeft), minLeft->data);
        }
    }
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
    treePointer delNode = *node;
    if(*node) {
        eraseNode(&(delNode->left));
        eraseNode(&(delNode->right));
        free(delNode);
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