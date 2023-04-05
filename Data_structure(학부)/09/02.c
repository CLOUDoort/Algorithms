/*
- listNode pointer type의 listPointer 선언
- 구조체 listNode 선언
- createList, insertList, printList 함수 선언
- 파일로부터 입력 받기
- 파일 닫기
- 입력값 sorting하기
- 동적할당한 node들 해제
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;

listPointer createList();
listPointer insertList(listPointer *first, listPointer x, int data);
void printList(listPointer first);

int main() {
	FILE* fp = fopen("in2.txt", "r");
	if (fp == NULL) {
		printf("Error\n");
		return 0;
	}
	listPointer first = NULL;
	listPointer x = first;
	int temp = 0;
	while (fscanf(fp, "%d", &temp) != EOF) {
		x = insertList(&first, x, temp);
	}
	int a = 0;
	while (1) {
		scanf("%d", &a);
		if (a == -1) break;
		listPointer temp = first;
		listPointer cur = first;
		int value = 0;
		if (cur) {
			if (cur->data > a) {
				listPointer newNode = createList();
				newNode->data = a;
				newNode->link = cur;
				first = newNode;
			}
			else {
				while (cur) {
					if (cur->data > a) {
						insertList(&first, temp, a);
						value = 1;
						break;
					}
					else if (cur->data == a) {
						break;
					}
					else {
						temp = cur;
						cur = cur->link;
					}
				}
				if(!value) insertList(&first, temp, a);
			}
		}
		else insertList(&first, temp, a);
		printList(first);
	}
	// 동적할당 해제
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

listPointer createList() {
	listPointer newNode = (listPointer)malloc(sizeof(*newNode));
	if (newNode == NULL) {
		printf("Memory Error\n");
		exit(-1);
	}
	return newNode;
}