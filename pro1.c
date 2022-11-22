#include <stdio.h>

int* average(int arr[][3], int row);
void sort(int *parr);
void print(int *parr);

int main()
{
        int arr[5][3];
        int i, j;
        for(i = 0; i < 5; i++) {
                for(j = 0; j < 3; j++) {
                        scanf("%d", &arr[i][j]);
                }
        }

        int *average_arr = average(arr, 5);
        sort(average_arr);
        print(average_arr);

        return 0;
}

int* average(int arr[][3], int row)
{
        static int average_arr[5];
        // 로컬변수의 포인터는 함수가 리턴될 때 반환되기 때문에 static으로 선언하여 변수의 수명을 프로그램 종료까지 한다.
        int i, j;
        int sum;

        for(i = 0; i < row; i++) {
                sum = 0;
                for(j = 0; j < 3; j++) {
                        sum += arr[i][j];
                }
                average_arr[i] = sum / 3;
        }
        return average_arr;

}

void sort(int *parr)
{
        int i, j;
        int temp;
        for(i = 0; i < 4; i++){
                for(j = 0; j < 4-i; j++) {
                        if(parr[j] < parr[j+1]) {
                                temp = parr[j];
                                parr[j] = parr[j+1];
                                parr[j+1] = temp;
                        }
                }
        }
}

void print(int *parr)
{
        int average, i, sum = 0;
        for(i = 0; i < 5; i++) {
                sum += parr[i];
        }
        average = sum / 5;
        printf("평균 : %d \n", average);
        for(i = 0; i < 5; i++) {
                if(parr[i] >= average) printf("%d, 합격\n", parr[i]);
                else printf("%d, 불합격 \n", parr[i]);
        }
}