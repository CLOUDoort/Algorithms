#include <iostream>
using namespace std;

int& function1(int& a)
{
    a = 5;
    return a;
}

int main()
{
    int b = 2;
    int c = function1(b);
    cout << c;
    return 0;
}

// 레퍼런스를 리턴하게 된다면 레퍼런스가 참조하는 타입의 크기와 상관없이 딱 한 번의 주소값 복사로 전달이 끝나게 된다. => 매우 효율적

// 레퍼런스 리턴하는 함수에서 지역 변수의 레퍼런스를 리턴하지 않도록 조심해야 한다.