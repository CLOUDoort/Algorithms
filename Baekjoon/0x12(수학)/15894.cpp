/*
    기본적으로 c++은 상수를 int 타입으로 계산한다.
*/

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    // 4는 단순 상수일 뿐이고, ll은 이 상수가 long long 타입임을 알려주는 장치이다.
    // => 상수 연산을 long long으로 할 수 있다.
    cout << 4ll*n;
}