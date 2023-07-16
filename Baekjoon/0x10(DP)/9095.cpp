/*
- 테이블 정의
    d[i] = i를 1, 2, 3의 합으로 나타내는 방법의 수
- 점화식 찾기
    d[i] = d[i-1]+d[i-2]+d[i-3]
*/

#include <bits/stdc++.h>
using namespace std;

int t, n;
int d[11];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    d[1] = 1; d[2] = 2; d[3] = 4;
    for(int i = 4; i < 11; i++) {
        d[i] = d[i-1]+d[i-2]+d[i-3];
    }
    while(t--) {
        cin >> n;
        cout << d[n] << '\n';
    }
}