/*
- 파일로부터 수식 입력받는다
- enum 생성한다.
- 스택 생성 및 구현한다.
    - push, pop함수
- getToken, postfix, print_token 함수 구현한다.
- 후위표기 변환 뒤 그 값을 문자열에 저장한다.
- 문자열에 저장한 후위표기 값을 계산하는 함수 구현한다.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100
typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;

int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};
int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
int stack[MAX_STACK_SIZE];
int postfix_stack[MAX_STACK_SIZE];
char postfix_expr[MAX_EXPR_SIZE];
char expr[MAX_EXPR_SIZE];
int top = -1;
int postfix_top = -1;

void push(precedence item, int a);
precedence pop(int a);
precedence getToken(char* symbol, int *n);
void postfix();
void print_token(precedence token);
int eval();

int main() {
    FILE *fp = fopen("in2.txt", "r");
    if(fp == NULL) {
        printf("Error\n");
        return 0;
    }
    fscanf(fp, "%s", expr);
    postfix();
    printf("%d", eval());
    fclose(fp);
    return 0;
}

int eval() {
    precedence token;
    char symbol;
    int op1, op2; int n = 0;
    for(token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)) {
        if(token == operand) push(symbol -'0', 1);
        else {
            op2 = pop(1); op1 = pop(1);
            switch(token) {
                case plus: push(op1+op2, 1); break;
                case minus: push(op1-op2, 1); break;
                case times: push(op1*op2, 1); break;
                case divide: push(op1/op2, 1); break;
                case mod: push(op1&op2, 1); break;
                default: break;
            }
        }
    }
    return pop(1);
}

void print_token(precedence token) {
    switch(token) {
        case 0: printf("%c ", '('); return;
        case 1: printf("%c ", ')'); return; 
        case 2: printf("%c ", '+'); return;
        case 3: printf("%c ", '-'); return;
        case 4: printf("%c ", '*'); return;
        case 5: printf("%c ", '/'); return;
        case 6: printf("%c ", '%'); return;
        default: return;
    }
}

void postfix() {
    char symbol; precedence token;
    int n = 0; top = 0; stack[0] = eos;
    for(token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)) {
        if(token == operand) {
            printf("%c ", symbol);
            postfix_expr[n] = symbol;
        }
        else if(token == rparen) {
            while(stack[top] != lparen) print_token(pop(0));
            pop(0);
        }
        else {
            while(isp[stack[top]] >= icp[token]) {
                print_token(pop(0));
            }
            push(token,0);
        }
    }
    while((token = pop(0))!= eos) print_token(token);
    printf("\n");
}

precedence getToken(char* symbol, int* n) {
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

void push(precedence item, int a) {
    if(a) {
        if(postfix_top >= MAX_STACK_SIZE -1) {
            printf("stack full\n");
            return;
        }
        postfix_stack[++postfix_top] = item;
    } else {
        if(top >= MAX_STACK_SIZE -1) {
            printf("stack full\n");
            return;
        }
        stack[++top] = item;
    }
}

precedence pop(int a) {
    if(a) {
        if(postfix_top == -1) {
            printf("No data\n");
            exit(1);
        }
        return postfix_stack[postfix_top--];
    }
    else {
        if(top == -1) {
            printf("No data\n");
            exit(1);
        }
        return stack[top--];
    }
}