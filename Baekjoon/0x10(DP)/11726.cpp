/*
- 테이블 정의하기
    - d[i] = 2xi 크기의 직사각형을 채우는 방법의 수
- 점화식 찾기
    - d[i] = d[i-1] + d[i-2];
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int d[1002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[1] = 1; d[2] = 2;
    for(int i = 3; i <= n; i++) {
        d[i] = (d[i-1] + d[i-2])%10007;
    }
    cout << d[n];
}