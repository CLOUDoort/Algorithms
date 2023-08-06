/*
    - 테이블 정의하기
        - d[i] = i를 그 합으로써 표현할 수 있는 제곱수 항의 최소 개수
*/

#include <bits/stdc++.h>
using namespace std;

int d[100002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        d[i] = d[i-1]+1;
        if(sqrt(i) == (int)sqrt(i)) d[i] = 1;
        else {
            int mn = 0x7f7f7f7f;
            for(int j = (int)sqrt(i); j > 0; j--) {
                mn = min(mn, d[j*j]+d[i-j*j]);
            }
            d[i] = mn;
        }
    }
    cout << d[n];
}