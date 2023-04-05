#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
};

listPointer createList();
listPointer insertList(listPointer* first, listPointer x, int data);
void printList(listPointer first);
void delList(listPointer *first, listPointer *pre, listPointer *cur);

int main() {
	FILE* fp = fopen("in.txt", "r");
	if (fp == NULL) {
		printf("Error\n");
		return 0;
	}
	listPointer first = NULL;
	listPointer x = first;
	int temp = 0;
	while ((fscanf(fp, "%d", &temp) != EOF)) {
		x = insertList(&first, x, temp);
	}
	int a = 0;
	while (1) {
		scanf("%d", &a);
		if (a == -1) break;
		listPointer pre = first;
		listPointer cur = first;
		int value = 0;
		if (cur) {
			if (cur->data > a) {
				listPointer newNode = createList();
				newNode->data = a;
				newNode->link = cur;
				first = newNode;
			}
			else if (cur->data == a) {
				first = first->link;
			}
			else {
				while (cur) {
					if (cur->data > a) {
						insertList(&first, pre, a);
						value = 1;
						break;
					}
					else if (cur->data == a) {
						delList(&first, &pre, &cur);
						value = 1;
						break;
					}
					else {
						pre = cur;
						cur = cur->link;
					}
				}
				if (!value) insertList(&first, pre, a);
			}
		}
		else insertList(&first, pre, a);
		printList(first);
	}
	while (first) {
		listPointer delNode = first;
		first = first->link;
		free(delNode);
	}
	fclose(fp);
	return 0;
}

void delList(listPointer *first, listPointer *pre, listPointer *cur) {
	(*pre)->link = (*cur)->link;
	free(*cur);
}

listPointer insertList(listPointer* first, listPointer x, int data) {
	listPointer newNode = createList();
	newNode->data = data;
	if (*first) {
		newNode->link = x->link;
		x->link = newNode;
	}
	else {
		newNode->link = NULL;
		*first = newNode;
	}
	return newNode;
}

void printList(listPointer first) {
	for (; first; first = first->link) {
		printf("%d ", first->data);
	}
	printf("\n");
}

listPointer createList() {
	listPointer newNode = (listPointer)malloc(sizeof(*newNode));
	return newNode;
}