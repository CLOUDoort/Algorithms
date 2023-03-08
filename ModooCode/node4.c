#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* nextNode;
    struct Node* prevNode;
};
struct Node* CreateNode(int data);
struct Node* InsertNode(int data, struct Node* pNode, struct Node* nNode);
void DestroyNode(struct Node* targetNode);
void printAllNode(struct Node* head);

int nodeNum = 0;


int main()
{
    struct Node* Node1 = CreateNode(100);
    struct Node* Node2 = InsertNode(200, Node1, NULL);
    struct Node* Node3 = InsertNode(300, Node2, NULL);
    struct Node* Node4 = InsertNode(400, Node3, NULL);
    struct Node* Node5 = InsertNode(500, Node4, NULL);

    printAllNode(Node1);
    DestroyNode(Node2);
    printAllNode(Node1);
}

void DestroyNode(struct Node* targetNode)
{
    struct Node* pNode = targetNode->prevNode;
    struct Node* nNode = targetNode->nextNode;

    pNode->nextNode = targetNode->prevNode;
    nNode->prevNode = targetNode->nextNode;

    nodeNum--;
    free(targetNode);
}

struct Node* InsertNode(int data, struct Node* pNode, struct Node* nNode)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head;
    newNode->data = data;
    newNode->nextNode = nNode;
    newNode->prevNode = pNode;

    pNode->nextNode = newNode;
    head = newNode->prevNode;

    // current->nextNode = newNode;

    return newNode;
}

struct Node* CreateNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prevNode = NULL;
    newNode->nextNode = NULL;
    nodeNum++;

    return newNode;
}
