/*
1. 작은 원판 n-1개를 2로 옮긴다.
2. 큰 원판 n을 3으로 옮긴다.
3. 작은 원판 n-1을 3으로 옮긴다.
=> 원판이 n-1개일 때 옮길 수 있으면 원판이 n개일 떄에도 옮길 수 있다.

- 해결방법
    - 함수의 정의
        - void func(int a, int b, int n);
        원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력하는 함수
    - base condition
        - n=1일 때, cout << a << ' ' << b << '\n';
    - 재귀 식
        - n-1개의 원판을 기둥 a에서 기둥 6-a-b로 옮긴다. func(a, 6-a-b, n-1);
        - n번 원판을 기둥 a에서 기둥 b로 옮긴다. cout << a << ' ' << b << '\n';
        - n-1개의 원판을 기둥 6-a-b에서 기둥 b로 옮긴다. func(6-a-b, b, n-1);
*/

#include <bits/stdc++.h>
using namespace std;

int n;

void func(int a, int b, int n) {
    if(n == 1)  {
        cout << a << ' ' << b << '\n';
        return;
    }
    func(a, 6-a-b, n-1);
    cout << a << ' ' << b << '\n';
    func(6-a-b, b, n-1);
}
 
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << (1<<n)-1 << '\n';
    func(1, 3, n);
}