#include <stdio.h>

typedef struct _empInfo {
    int empNum; // 직원의 고유 번호 : Key
    int age; // 직원의 나이 : value
} EmpInfo;

// 키를 결정했으면 이를 기반으로 데이터를 단번에 찾을 수 었어야 테이블이라 할 수 있다.
int main(void) {
    EmpInfo empInfoArr[1000];
    EmpInfo ei;
    int eNum;

    printf("사번과 나이 입력 : ");
    scanf("%d %d", &(ei.empNum), &(ei.age));
    empInfoArr[ei.empNum] = ei;

    printf("확인하고픈 직원의 사번 입력 : ");
    scanf("%d", &eNum);

    ei = empInfoArr[eNum];
    printf("사번 : %d, 나이 : %d \n", ei.empNum, ei.age);
    return 0;

}