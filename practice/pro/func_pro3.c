#include <stdio.h>

int multiply(int N, int sum, int i);

int main()
{
    int N;
    int sum = 1;
    int i = 1;
    scanf("%d", &N);

    printf("1부터 N까지 곱한 값 : %d\n", multiply(N, sum, i));
    return 0;
}

int multiply(int N, int sum, int i)
{
    if(i <= N) {
        sum *= i;
        i++;
       return  multiply(N, sum, i);
    } else return sum;
}