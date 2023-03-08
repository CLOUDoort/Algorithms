#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* nextNode;
    struct Node* prevNode;
};
struct Node* CreateNode(int data);
struct Node* InsertNode(struct Node* current, int data);
void DestroyNode(struct Node* destroy, struct Node* head);
void PrintNodeFrom(struct Node* from);
int CountNodeFrom(struct Node* from);
bool HasNode(struct Node* search, struct Node* head);

int main()
{
    struct Node* Node1 = CreateNode(100);
    struct Node* Node2 = InsertNode(Node1, 200);
    struct Node* Node3 = InsertNode(Node2, 300);
    struct Node* Node4 = InsertNode(Node2, 400);

    // DestroyNode(Node2, Node1);
    printf("노드의 수는 ? : %d \n", CountNodeFrom(Node1));
    PrintNodeFrom(Node1);
    printf("Node2가 있습니까? : %s \n", HasNode(Node2, Node1) ? "true" : "false");

}

bool HasNode(struct Node* search, struct Node* head)
{
    while(head) {
        if(search->data == head->data) {
            return 1;
        }
        head = head->nextNode;
    }
    return 0;
}

void PrintNodeFrom(struct Node* from) 
{
    while(from) {
        printf("Node : %d \n", from->data);
        from = from->nextNode;
    }
}

int CountNodeFrom(struct Node* from) 
{
    int sum = 0;
    while(from) {
        sum++;
        from = from->nextNode;
    }
    return sum;
}

void DestroyNode(struct Node* destroy, struct Node* head)
{
    if(destroy == head) {
        free(destroy);
        return;
    }
    while(head) {
        if(head->nextNode == destroy) {
            head->nextNode = destroy->nextNode;
            (destroy->nextNode)->prevNode = head;
        }
        head->prevNode = head;
        head = head->nextNode;
    }
    free(destroy);
}

struct Node* InsertNode(struct Node* current, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->nextNode = current->nextNode;
    newNode->prevNode = current;

    current->nextNode = newNode;
    return newNode;
}

struct Node* CreateNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;

    return newNode;
}
