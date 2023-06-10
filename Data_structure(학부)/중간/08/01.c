/*
- 파일로부터 수식 입력받는다.
- enum, stack,expr 생성
    - push, pop함수 생성
- print_token, getToken, postfix 변환 함수 생성한다.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_EXPR_SIZE 100
#define MAX_STACK_SIZE 100
typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;

// precedence 우선순위
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0};
// 스택안에서는 왼쪽괄호 우선순위 제일 낮게
int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0};

int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int top = -1;

void push(precedence item);
precedence pop();
void postfix();
precedence getToken(char *symbol, int *n);
void print_token(precedence token);

int main() {
    FILE* fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("Error\n");
        return 0;
    }
    fscanf(fp, "%s", expr);
    postfix();
    fclose(fp);
    return 0;
}

void print_token(precedence token) {
    switch(token) {
        case 0: printf("%c ", '(');break;
        case 1: printf("%c ", ')');break;
        case 2: printf("%c ", '+');break;
        case 3: printf("%c ", '-');break;
        case 4: printf("%c ", '*');break;
        case 5: printf("%c ", '/');break;
        case 6:printf("%c ", '%');break;
        default: break;
    }
}

void postfix() {
    char symbol;
    precedence token;
    int n = 0;
    top = 0; stack[0] = eos;
    for(token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)) {
        if(token == operand) printf("%c ", symbol);
        // 오른쪽 괄호가 나오면 왼쪽 괄호 나올 때까지 pop, 출력
        else if(token == rparen) {
            while(stack[top] != lparen) {
                print_token(pop());
            }
            pop();
        }
        else {
            // 스택에 있는 token이 들어오려는 token보다 크다면 출력하고 스택에 push
            // 만약 들어오려는 token이 더 크다면 스택에 Push
            while(isp[stack[top]] >= icp[token]) {
                print_token(pop());
            }
            push(token);
        }
    }
    // 스택에 남아있는 토큰 출력
    while((token = pop()) != eos) print_token(token);
    printf("\n");
}

precedence getToken(char *symbol, int *n) {
    *symbol = expr[(*n)++];
    switch(*symbol) {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '/': return divide;
        case '*': return times;
        case '%': return mod;
        case '\0': return eos;
        default: return operand;
    }
}

void push(precedence item) {
    if(top >= MAX_STACK_SIZE-1) {
        printf("stack full\n");
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