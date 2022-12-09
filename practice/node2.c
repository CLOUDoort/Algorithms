#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
        int data;
        struct Node* nextNode;
};
struct Node* CreateNode(int data);
void PrintNodeFrom(struct Node* from);
struct Node* InsertNode(struct Node* current, int data);
void DestroyNode(struct Node* destroy, struct Node* head);
int CountNode(struct Node* head);
bool HasNode(struct Node* head, struct Node* search);

int main()
{
        struct Node* Node1 = CreateNode(100);
        struct Node* Node2 = InsertNode(Node1, 200);
        struct Node* Node3 = InsertNode(Node2, 300);
        struct Node* Node4 = InsertNode(Node2, 400);

        PrintNodeFrom(Node1);
        DestroyNode(Node3, Node1);
        printf("Node의 수는 : %d \n", CountNode(Node1));
        printf("Node3가 있나요? : %s \n", HasNode(Node1, Node3) ? "true" : "false");
        return 0;
}
bool HasNode(struct Node* search, struct Node* head)
{
        bool x = false;
        while(head) {
                if(search->data == head->data) {
                        x = true;
                        return x;
                }
                 head = head->nextNode;
        }
        return x;
}

struct Node* CreateNode(int data)
{
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->nextNode = NULL;

        return newNode;
}
struct Node* InsertNode(struct Node* current, int data)
{
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->nextNode = current->nextNode;

        current->nextNode = newNode;

        return newNode;
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
                }
                head = head->nextNode;
        }
        free(destroy);
}
void PrintNodeFrom(struct Node* from)
{
        while(from) {
                printf("노드의 값 : %d \n", from->data);
                from = from->nextNode;
        }
};
int CountNode(struct Node* head)
{
        int sum = 0;
        while(head) {
                sum++;
                head = head->nextNode;
        }
        return sum;
}