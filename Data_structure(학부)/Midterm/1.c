// 2017116145 - 강준석
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 30
typedef enum {
    lparen, rparen, plus, minus, times, divide, mod, not, and, money, eos, operand
} precedence;

int isp[] = {0, 19, 12, 12, 13, 13, 13, 15, 8};
int icp[] = {20, 19, 12, 12, 13, 13, 13, 15, 8};

int stack[MAX_SIZE];
char expr[MAX_SIZE];
int top = -1;

void push(precedence token);
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
    fscanf(fp, "%s", expr);
    postfix();
    fclose(fp);
    return 0;
}

void printToken(precedence token) {
    switch(token) {
        case 0: printf("("); break;
        case 1: printf(")"); break;
        case 2: printf("+"); break;
        case 3: printf("-"); break;
        case 4: printf("*"); break;
        case 5: printf("/"); break;
        case 6: printf("%%"); break;
        case 7: printf("!"); break;
        case 8: printf("&"); break;
        case 9: printf(NULL); break;
        default: break;
    }
}

void postfix() {
    char symbol; precedence token;
    int n = 0; top = 0; stack[0] = eos;
    for(token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)) {
        if(token == operand) {
            printf("%c", symbol);
        }
        else if(token == rparen) {
            while(stack[top] != lparen) {
                printToken(pop());
            }
            pop();
        }
        else if(token == money) {
            printToken(pop());
            return;
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

void push(precedence item) {
    if(top >= MAX_SIZE-1) {
        printf("Full\n");
        exit(1);
    }
    stack[++top] = item;
}

precedence pop() {
    if(top < 0) {
        printf("Empty\n");
        exit(1);
    }
    return stack[top--];
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
        case '!': return not;
        case '&': return and;
        case '$': return money;
        case '\0': return eos;
        default: return operand;
    }
}