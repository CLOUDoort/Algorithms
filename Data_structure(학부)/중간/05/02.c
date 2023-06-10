/*
- 아이디어
    - 다항식 함수의 계수와 지수 저장할 구조체 Polynomial만든다.
    - 전역변수 avail 선언한다.
    - Polynomial 구조체 배열을 만든다.
    - 입력받을 다항식의 start와 end index를 초기화하고 in.txt로부터 다항식 수를 받는다.
    - 다항식 계수와 지수 데이터 입력받는 함수 생성한다. 
    - 다항식 출력 함수 생성한다.
    - 다항식 덧셈 함수 생성한다.
    - 덧셈한 다항식 출력해준다.
*/

#include <stdio.h>
#include <stdlib.h>
#define COMPARE(a, b) ((a) > (b) ? 1 : ((a) == (b) ? 0 : -1))
#define MAX_TERMS 101

typedef struct _poly {
    float coef;
    int expon;
} Polynomial;

Polynomial terms[MAX_TERMS];
int avail = 0;

void input_data(FILE *fp, int ps, int pe);
void print_data(int As, int Ae, char target);
void padd(int As, int Ae, int Bs, int Be, int*Cs, int*Ce);
void attach(float coef, int expon);

int main() {
    FILE *fp = fopen("in.txt", "r");
    if(fp == NULL) {
        fprintf(stderr, "Error!\n");
        exit(1);
    }
    int As = 0, Ae, Bs, Be, Cs, Ce;
    fscanf(fp, "%d", &Ae); Ae--;
    fscanf(fp, "%d", &Be); Be--;
    printf("<< D(x) = A(x) + B(x) >>\n");
    Bs = Ae+1;
    Be = Bs+Be;

    input_data(fp, As, Ae);
    input_data(fp, Bs, Be);

    print_data(As, Ae, 'A');
    print_data(Bs, Be, 'B');

    padd(As, Ae, Bs, Be, &Cs, &Ce);
    print_data(Cs, Ce, 'D');

    fclose(fp);
    return 0;
}

void attach(float coef, int expon) {
    if(avail >= MAX_TERMS) {
        fprintf(stderr, "다항식 함수가 너무 많습니다! \n");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail++].expon = expon;
}

void input_data(FILE *fp, int ps, int pe) {
    for(int i = ps; i <= pe; i++) {
        float c = 0;
        int e = 0;
        fscanf(fp, "%f %d", &c, &e);
        attach(c, e);
    }
}

void print_data(int ps, int pe, char target) {
    printf("%c(x) = ", target);
    for(int i = ps; i <= pe-1; i++) {
        printf("%3fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%3f\n", terms[pe].coef);
}

void padd(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
    *Cs = avail;
    float tempTerms;
    while(As <= Ae && Bs <= Be) {
        switch(COMPARE(terms[As].expon, terms[Bs].expon)) {
            case 1:
                attach(terms[As].coef, terms[As].expon);
                As++;
                break;
            case 0:
                tempTerms = terms[As].coef + terms[Bs].coef;
                if(tempTerms) attach(tempTerms, terms[As].expon);
                As++;
                Bs++;
                break;
            case -1:
                attach(terms[Bs].coef, terms[Bs].expon);
                Bs++;
                break;
        }
    }
    for(; As <= Ae; As++) {
        attach(terms[As].coef, terms[As].expon);
    }
    for(; Bs <= Be; Bs++) {
        attach(terms[Bs].coef, terms[Bs].expon);
    }
    *Ce = avail-1;
}