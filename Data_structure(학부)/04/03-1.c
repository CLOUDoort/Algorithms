#include <stdio.h>
#include <stdlib.h>

typedef struct _student {
    char name[20];
    int student_id;
    float score;
} Student;

void initStruct(Student *st, int n);
void printStruct(Student *st, int n);

int main() {
    Student* arr = (Student*)malloc(sizeof(*arr)*20);
    char a; int n = 0;
    while(1) {
        printf("input 'a' or 'q'> ");
        scanf(" %c", &a);
        if(a == 'q') break;
        initStruct(arr, n);
        n++;
    }
    printStruct(arr, n);
    free(arr);
    return 0;
}

void printStruct(Student *st, int n) {
    float sum = 0;
    for(int i = 0; i < n; i++) {
        printf("%s %d %.1f\n", st[i].name, st[i].student_id, st[i].score);
        sum += st[i].score;
    }
    printf("------------\n");
    printf("학점평균 : %.1f\n", sum/n);
}

void initStruct(Student *st, int n) {
    scanf("%s %d %f", st[n].name, &st[n].student_id, &st[n].score);
}