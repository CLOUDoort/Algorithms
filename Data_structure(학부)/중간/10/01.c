/*
- polyNode, polyPointer 선언
- createList, insertList 구현
- 파일로부터 값을 입력받는다.
- 다항식 덧셈하는 함수 padd 구현한다.
- 다항식 붙이는 attach함수와 출력하는 print함수 구현한다.
- 메모리 할당 해제하는 함수 erase 구현한다.
- 파일스트림 닫는다.
*/
#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x, y) ((x) < (y) ? -1 : ((x) == (y) ? 0 : 1))

typedef struct polyNode* polyPointer;
typedef struct polyNode {
    int coef;
    int expon;
    polyPointer link;
}polyNode;

polyPointer createList();
polyPointer insertList(polyPointer *first, polyPointer pre, int x, int y);
polyPointer padd(polyPointer A, polyPointer B);
void attach(int coefficent, int exponent, polyPointer *prt);
void printPoly(polyPointer a);
void erase(polyPointer *ptr);

int main() {
    FILE* fp1 = fopen("in1.txt", "r");
    if(fp1 == NULL) {
        printf("Error\n");
        return 0;
    }
    FILE* fp2 = fopen("in2.txt", "r");
    if(fp2 == NULL) {
        printf("Error\n");
        return 0;
    }
    polyPointer a = NULL, b = NULL;

    polyPointer preA = a, preB = b;
    int x = 0, y = 0;
    while(fscanf(fp1, "%d %d", &x, &y) != EOF) {
        preA = insertList(&a, preA, x, y);
    }
    while(fscanf(fp2, "%d %d", &x, &y) != EOF) {
        preB = insertList(&b, preB, x, y);
    }
    polyPointer c = padd(a, b);
    printPoly(c);

    erase(&a); erase(&b); erase(&c);

    fclose(fp1); fclose(fp2);
    return 0;
}

void erase(polyPointer *ptr) {
    polyPointer delNode;
    while(*ptr) {
        delNode = *ptr;
        *ptr = (*ptr)->link;
        free(delNode);
    }
}

void printPoly(polyPointer a) {
    while(a) {
        printf("%d %d ", a->coef, a->expon);
        a = a->link;
    }
}

polyPointer padd(polyPointer a, polyPointer b) {
    polyPointer c, rear, temp;
    int sum;
    // dummy node 생성
    rear = createList();
    c = rear;
    while(a && b) {
        switch(COMPARE(a->expon, b->expon)) {
            case -1: {
                attach(b->coef, b->expon, &rear);
                b = b->link;
                break;
            }
            case 0: {
                sum = a->coef + b->coef;
                if(sum) attach(sum, a->expon, &rear);
                a = a->link; b = b->link; break;
            }
            case 1: {
                attach(a->coef, a->expon, &rear);
                a = a->link;
                break;
            }
        }
    }
    for(; a; a = a->link) attach(a->coef, a->expon, &rear);
    for(; b; b = b->link) attach(b->coef, b->expon, &rear);
    rear->link = NULL;
    temp = c; c = c->link; free(temp);
    return c;

}

void attach(int coefficent, int exponent, polyPointer *ptr) {
    polyPointer newNode = createList();
    newNode->coef = coefficent;
    newNode->expon = exponent;
    (*ptr)->link = newNode;
    *ptr = newNode;
}

polyPointer insertList(polyPointer *first, polyPointer pre, int x, int y) {
    polyPointer newNode = createList();
    newNode->coef = x; newNode->expon = y;
    if(*first) {
        newNode->link = pre->link;
        pre->link = newNode;
    }
    else {
        newNode->link = NULL;
        *first = newNode;
    }
    return newNode;
}

polyPointer createList() {
    polyPointer newNode = (polyPointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("create error\n");
        exit(-1);
    }
    return newNode;
}