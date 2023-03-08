#include <iostream>
using namespace std;
int main()
{
    int arr[3] = {1, 2, 3};
    int(&ref)[3] = arr;

    ref[0] = 2;
    ref[1] = 3;
    ref[2] = 1;

    cout << arr[0] << arr[1] << arr[2] << endl;
    return 0;
}


// 배열의 레퍼런스인 경우, 참조하기 위해선 반드시 배열의 크기를 명시해야 한다.