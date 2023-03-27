/*
- 아이디어
    - 데이터 key를 가지는 구조체 Element를 선언한다.
    - 전역변수 top과 capacity를 각각 -1과 1로 초기화한다.
    - 구조체 배열을 동적할당한다.
    - stackFull, stackEmpty, push, pop함수를 구현한다.
    - 입력받은 문자열을 기반으로 프로그램 구동한다.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _stack {
    int key;
} Element;

Element Stack;

int top = -1;
int capacity = 1;
int arr[100];

void stackRealloc(Element *stack) {
    Element* newStack = (Element*)realloc(stack, 2*capacity*sizeof(Stack));
    capacity *= 2;
    stack = newStack;
}

int stackEmpty(Element *stack) {
    if(top < 0) {
        printf("Stack empty\n");
        return 1;
    }
    else return 0;
}

int stackFull(Element *stack) {
    if(top >= capacity-1) return 1;
    else return 0;
}

void push(Element *stack, int data) {
    if(stackFull(stack)) stackRealloc(stack);
    stack[++top].key = data;
}

int pop(Element *stack) {
    if(!stackEmpty(stack)) return stack[top--].key;
    else return 0;
}

int main() {
    Element* stack = (Element*)malloc(sizeof(Stack));
    char c = ' ';
    while(c != 'F') {
        scanf(" %c", &c);
        if(c == 'I') {
            int a;
            scanf("%d", &a);
            push(stack, a);
        }
        else if(c == 'D') pop(stack);
    }
    int n = 0;
    while(top > -1) arr[n++] = pop(stack);
    for(int i = n-1; i >= 0; i--) printf("%d ", arr[i]);
    return 0;
}
