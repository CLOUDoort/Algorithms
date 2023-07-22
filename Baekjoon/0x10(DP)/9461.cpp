/*
    - 테이블 정의
        - d[i] = i번째 변의 길이
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll d[101];
int t, n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    d[1] = 1; d[2] = 1; d[3] = 1;
    for(int i = 4; i <= 100; i++) {
        d[i] = d[i-2]+d[i-3];
    }
    while(t--) {
        cin >> n;
        cout << d[n] << '\n';
    }
}