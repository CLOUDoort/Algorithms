#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer llink;
	listPointer rlink;
}listNode;

listPointer createNode();
listPointer insertNode(listPointer *head, int data);
void printNode(listPointer head);
void invertPrintNode(listPointer last);
void eraseNode(listPointer* head);

int main() {
	FILE* fp = fopen("in.txt", "r");
	if (fp == NULL) {
		printf("File read error\n");
		exit(1);
	}
	listPointer head = NULL, last = NULL;
	int data = 0;
	while (fscanf(fp, "%d", &data) != EOF) {
		last = insertNode(&head, data);
	}

	printNode(head);
	invertPrintNode(last);
	eraseNode(&head);

	fclose(fp); 
	return 0;
}

listPointer insertNode(listPointer* head, int data) {
	listPointer cur = *head, pre = *head;
	listPointer newNode = createNode();
	newNode->data = data;
	if (*head) {
		while (cur) {
			pre = cur;
			cur = cur->rlink;
		}
		newNode->llink = pre;
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
	}
	else {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		*head = newNode;
	}
	return newNode;
}

void invertPrintNode(listPointer last) {
	while (last) {
		printf("%d ", last->data);
		last = last->llink;
	}
	printf("\n");
}

void printNode(listPointer head) {
	while (head) {
		printf("%d ", head->data);
		head = head->rlink;
	}
	printf("\n");
}

void eraseNode(listPointer* head) {
	listPointer delNode;
	while (*head) {
		delNode = *head;
		*head = (*head)->rlink;
		free(delNode);
	}
}

listPointer createNode() {
	listPointer newNode = (listPointer)malloc(sizeof(*newNode));
	if (newNode == NULL) {
		printf("malloc error\n");
		exit(1);
	}
	return newNode;
}