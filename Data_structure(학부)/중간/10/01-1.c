#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x, y) ((x) < (y) ? -1 : ((x) == (y) ? 0 : 1))

typedef struct polyNode* polyPointer;
typedef struct polyNode {
    float coef;
    int expon;
    polyPointer link;
} polyNode;

polyPointer createNode();
void insertNode(polyPointer *first, float coef, int expon);
void printNode(polyPointer first);
void freeNode(polyPointer *first);
polyPointer padd(polyPointer A, polyPointer B);
void attach(float coef, int expon, polyPointer *ptr);

int main() {
    FILE *fp1 = fopen("in1.txt", "r");
    if(fp1 == NULL) {
        printf("File read error\n");
        exit(1);
    }
    FILE *fp2 = fopen("in2.txt", "r");
    if(fp2 == NULL) {
        printf("File read error\n");
        exit(1);
    }
    polyPointer Afirst = NULL, Bfirst = NULL;
    float coef; int expon;
    while(fscanf(fp1, "%f %d", &coef, &expon)) {
        insertNode(&Afirst, coef, expon);
    }
    while(fscanf(fp2, "%f %d", &coef, &expon)) {
        insertNode(&Bfirst, coef, expon);
    }
    polyPointer C = padd(Afirst, Bfirst);
    printNode(C);
    freeNode(&C);
    fclose(fp1); fclose(fp2);
    return 0;
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
void attach(float coef, int expon, polyPointer *ptr) {
    polyPointer temp = createNode();
    temp->coef = coef;
    temp->expon = expon;
    (*ptr)->link = temp;
    *ptr = temp;
}

void printNode(polyPointer first) {
    while(first) {
        printf("%f %d ", first->coef, first->expon);
        first = first->link;
    }
}
void freeNode(polyPointer *first) {
    polyPointer delNode;
    while(*first) {
        delNode = *first;
        *first = (*first)->link;
        free(delNode);
    }
}

void insertNode(polyPointer *first, float coef, int expon) {
    polyPointer pre, cur = *first;
    polyPointer newNode = createNode();
    newNode->coef = coef; newNode->expon = expon;
    if(*first) {
        while(cur) {
            pre = cur;
            cur = cur->link;
        }
        newNode->link = pre->link;
        pre->link = newNode;
    }
    else {
        newNode->link = NULL;
        *first = newNode;
    }
}

polyPointer createNode() {
    polyPointer newNode = (polyPointer)malloc(sizeof(*newNode));
    if(newNode == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    return newNode;
}