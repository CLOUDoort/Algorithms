#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *nextNode;
};
struct Node* CreateNode(int data);
struct Node* InsertNode(struct Node *current, int data);
void DestroyNode(struct Node *destroy, struct Node *head);
void PrintNodeFrom(struct Node* from);

int main()
{
    struct Node* Node1 = CreateNode(100);
  struct Node* Node2 = InsertNode(Node1, 200);
  struct Node* Node3 = InsertNode(Node2, 300);
  /* Node 2 뒤에 Node4 넣기 */
  struct Node* Node4 = InsertNode(Node2, 400);
  DestroyNode(Node2, Node1);

    PrintNodeFrom(Node1);
    return 0;
}

struct Node* CreateNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->nextNode = NULL;

    return newNode;
}
struct Node* InsertNode(struct Node* current, int data)
{
    struct Node* after = current->nextNode;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->nextNode = after;
    current->nextNode = newNode;

    return newNode;
}

void DestroyNode(struct Node *destroy, struct Node *head)
{
    struct Node* next = head;   
    // 첫 번째 node 파괴
    if(destroy == head) {
        free(destroy);
        return;
    }

    while(next) {
        if(next->nextNode == destroy) {
            next->nextNode = destroy->nextNode;
        }
        next = next->nextNode;
    }
    free(destroy);
}

void PrintNodeFrom(struct Node *from)
{
    while(from) {
        printf("노드의 데이터 : %d \n", from->data);
        from = from->nextNode;
    }
}