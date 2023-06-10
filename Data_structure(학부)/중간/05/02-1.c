#include <stdio.h>
#define MAX_TERMS 101
#define COMPARE(x, y) ((x) < (y) ? -1 : ((x) == (y) ? 0 : 1))

typedef struct _poly {
    float coef;
    int expon;
} Polynomials;

Polynomials terms[MAX_TERMS];
int avail = 0;
char num[10][3] = {"st", "nd", "rd"};

void padd();
void attach(float coefficient, int expon);
void initPoly(FILE *fp, int a, int b);
void printPoly(int ps, int pe, char target);
void padd(int startA, int finishA, int startB, int finishB, int *startD, int* finishD);

int main() {
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        printf("FILE Error\n");
        return 0;
    }
    int a, b;
    printf("<< D(x) = A(x) + B(x) >>\n");
    fscanf(fp, "%d", &a);
    fscanf(fp, "%d", &b);

    int startA = 0, finishA = a-1, startB = a, finishB = a+b-1; 
    int startD, finishD;
    initPoly(fp, a, b);
    printPoly(startA, finishA, 'A');
    printPoly(startB, finishB, 'B');
    padd(startA, finishA, startB, finishB, &startD, &finishD);
    printPoly(startD, finishD, 'D');
    return 0;
}

void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD) {
    float sum;
    *startD = avail;
    while(startA <= finishA && startB <= finishB) {
        switch(COMPARE(terms[startA].expon, terms[startB].expon)) {
            case -1: {
                attach(terms[startB].coef, terms[startB].expon);
                startB++; break;
            }
            case 0: {
                sum = terms[startA].coef + terms[startB].coef;
                if(sum) attach(sum, terms[startA].expon);
                startA++; startB++; break;
            }
            case 1: {
                attach(terms[startA].coef, terms[startA].expon);
                startA++;
            }
        }
    }
    for(; startA <= finishA; startA++)attach(terms[startA].coef, terms[startA].expon);
    for(; startB <= finishB; startB++)attach(terms[startB].coef, terms[startB].expon);
    *finishD = avail-1;
}


void printPoly(int ps, int pe, char target) {
    printf("%c(x) = ", target);
    for(int i = ps; i < pe; i++) {
        printf("%fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%f\n", terms[pe].coef);
}

void initPoly(FILE *fp, int a, int b) {
    float coef; int expon;
    for(int i = 1; i <= a; i++) {
        fscanf(fp, "%f %d", &coef, &expon);
        attach(coef, expon);
    }
    for(int i = 1; i <= b; i++) {
        fscanf(fp, "%f %d", &coef, &expon);
        attach(coef, expon);
    }
}

void attach(float coefficient, int expon) {
    if(avail >= MAX_TERMS) {
        printf("To many terms!\n");
        return;
    }
    terms[avail].coef = coefficient;
    terms[avail++].expon = expon;
}