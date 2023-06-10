#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum {
    lparen,
    rparen,
    plus,
    minus,
    times,
    divide,
    mod,
    eos,
    operand
} precedence;

int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
int icp[] = {20, 19, 12, 12, 13, 13,13, 0};
precedence stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int top = -1;

void push(int token);
precedence pop();
precedence getToken(char *symbol, int *n);
void postfix();
void printToken(precedence token);

int main() {
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("File read error\n");
        exit(1);
    }
    int n = 0;
    while(fscanf(fp, "%c", &expr[n]) != EOF) n++;
    postfix();
    fclose(fp);
    return 0;
}

void printToken(precedence token) {
    switch(token) {
        case 0: {
            printf("( ");
            break;
        }
        case 1: {
            printf(") ");
            break;
        }
        case 2: {
            printf("+ ");
            break;
        }
        case 3: {
            printf("- ");
            break;
        }
        case 4: {
            printf("* ");
            break;
        }
        case 5: {
            printf("/ ");
            break;
        }
        case 6: {
            printf("%% ");
            break;
        }
        default: return;
    }
}

void postfix() {
    char symbol; precedence token;
    int n = 0; top = 0; stack[0] = eos;
    for(token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)) {
        if(token == operand) printf("%c ", symbol);
        else if(token == rparen) {
            while(stack[top] != lparen) {
                printToken(pop());
            }
            pop();
        }
        else {
            while(isp[stack[top]] >= icp[token]) {
                printToken(pop());
            }
            push(token);
        }
    }
    while((token = pop()) != eos) printToken(token);
    printf("\n");
}

precedence getToken(char *symbol, int *n) {
    *symbol = expr[(*n)++];
    switch(*symbol) {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        case '\0': return eos;
        default: return operand;
    }
}


void push(int token) {
    if(top >= MAX_STACK_SIZE -1) {
        printf("Full\n");
        exit(1);
    }
    stack[++top] = token;
}
precedence pop() {
    if(top < 0) {
        printf("empty\n");
        exit(1);
    }
    return stack[top--];
}
