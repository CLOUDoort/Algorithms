/*
- 아이디어
    - Student 구조체 만든다.
    - 구조체 동적 배열 생성한다.
    - 데이터 입력 함수를 생성한다.
    - 배열 데이터 및 평균 출력 함수를 생성한다.
    - 동적 메모리 해제해준다.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _student {
    char name[20];
    int student_id;
    float score;
} Student;

int addData(Student* student) {
    int cnt = 0;
    char value = ' ';
    while(value != 'q') {
        printf("input 'a' or 'q' > ");
        scanf("%c", &value);
        if(value == 'a') {
            scanf("%s %d %f", student[cnt].name, &student[cnt].student_id, &student[cnt].score);
            cnt++;
        }
        getchar();
    }
    return cnt;
}

void printData(Student* student, int n) {
    float sum = 0;
    for(int i = 0; i < n; i++) {
        printf("%s %d %.1f\n", student[i].name, student[i].student_id, student[i].score);
        sum += student->score;
    }
    printf("------------\n");
    printf("학점평균 : %.1f\n", sum/n);
}

int main() {
    Student* student = (Student*)malloc(sizeof(Student)*20);
    int n = addData(student);
    printData(student, n);
    free(student);
    return 0;
}