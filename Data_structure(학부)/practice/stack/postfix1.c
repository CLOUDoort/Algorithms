#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;

int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int top = -1;

void push(precedence item) {
    if(top >= MAX_STACK_SIZE-1) {
        printf("Full\n");
        return;
    }
    stack[++top] = item;
}

precedence pop() {
    if(top == -1) {
        printf("No data\n");
        exit(1);
    }
    return stack[top--];
}

precedence getToken(char *symbol, int *n) {
    *symbol = expr[(*n)++];
    switch(*symbol) {
        case '(': return lparen;
        case ')': return lparen;
        case '+': return lparen;
        case '-':return lparen;
        case '/': return lparen;
        case '*': return lparen;
        case '%': return lparen;
        case '\0': return lparen;
        default : return operand;
    }
}

int eval(void) {
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0;
    token = getToken(&symbol, &n);
    while(token != eos) {
        
    }
}

int main() {
    scanf("%s", expr);
    printf("%s", eval());
}

