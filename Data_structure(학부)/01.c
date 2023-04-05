#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
};

listPointer createList();
void insertList(listPointer *first, listPointer *x, int data);
void printList(listPointer first);

int main() {
	FILE* fp = fopen("in1.txt", "r");
	if (fp == NULL) {
		printf("Error\n");
		return 0;
	}
	listPointer first = NULL;
	int temp = 0;
	listPointer x = first;
	while (fscanf(fp, "%d", &temp) != EOF) insertList(&first, &x, temp);
	printList(first);
	while (first) {
		listPointer delNode = first;
		first = delNode->link;
		free(delNode);
	}
	fclose(fp);
	return 0;
}

void printList(listPointer first) {
	for (; first; first = first->link) {
		printf("%d ", first->data);
	}
	printf("\n");
}

void insertList(listPointer *first, listPointer *x, int data) {
	listPointer newNode = createList();
	newNode->data = data;
	if (*first) {
		newNode->link = (*x)->link;
		(*x)->link = newNode;
	}
	else {
		newNode->link = NULL;
		*first = newNode;
	}
	*x = newNode;
}

listPointer createList() {
	listPointer newNode = (listPointer)malloc(sizeof(*newNode));
	if (newNode == NULL) {
		printf("Memory Error\n");
		exit(-1);
	}
	return newNode;
}