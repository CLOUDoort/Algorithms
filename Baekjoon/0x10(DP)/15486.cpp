/*
- 테이블 정의
    - d[i] = i-1번째 날까지 상담했을 경우 최대 금액
*/

#include <bits/stdc++.h>
using namespace std;

int n, d[1500002], t[1500002], p[1500002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> t[i] >> p[i];
    for(int i = 1; i <= n; i++) {
        d[i] = max(d[i], d[i-1]);
        if(i+t[i]-1 <= n) {
            d[i+t[i]] = max(d[i+t[i]], d[i]+p[i]);
        }
    }
    cout << max(d[n], d[n+1]);
}