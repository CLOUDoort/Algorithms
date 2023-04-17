#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int key;
} Element;

Element *stack;

int top = -1;
int capacity = 1;

void push(int a) {
    if(top >= capacity-1) {
        stackFull();
    }
    stack[++top].key = a;
}

Element pop() {
    if(top < 0) {
        exit(-1);
    }
    return stack[top--];
}

void stackEmpty() {

}

void stackFull() {
    stack = realloc(stack, 2*capacity*sizeof(*stack));
    capacity *= 2;
}

int main() {
    stack = (Element*)malloc(sizeof(*stack));
    char c;
    while(1) {
        scanf(" %c", &c);
        if(c == 'F') break;
        else if(c == 'I') {
            int a;
            scanf("%d", &a);
            push(a);
        }
        else if(c == 'D') {
            pop();
        }
    }
}