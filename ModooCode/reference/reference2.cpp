#include <iostream>
using namespace std;

int change_val(int &p) {
    p = 3;

    return 0;
}

int main() 
{
    int number = 5;

    cout << number << endl;
    change_val(number);
    cout << number << endl;

    return 0;
}

// 레퍼런스는 반드시 처음에 누구의 별명이 될 것인지 지정해야 한다.
// 레퍼런스가 한 번 별명이 되면 절대로 다른 이의 별명이 될 수 없다.
// 레퍼런스는 메모리 상에 존재하지 않을 수도 있다. => 기존 변수로 바꿔치기 하면 되기 때문, 그렇다고 항상 존재하지 않는 것은 아니다.