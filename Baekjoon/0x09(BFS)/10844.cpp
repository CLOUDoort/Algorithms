/*
- 테이블 정의
    - d[i] = 길이가 i인 수의 계단수의 총 개수
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll d[102][10];
ll mod = 1000000000;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;

    for(int i = 1; i <= 9; i++) {
        d[1][i] = 1;
    }
    d[1][0] = 0;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j == 0) d[i][j] = d[i-1][j+1]%mod;
            else if(j == 9) d[i][j] = d[i-1][j-1]%mod;
            else d[i][j] = d[i-1][j-1]+d[i-1][j+1]%mod;
        }
    }
    
    ll sum = 0;
    for(int i = 0; i <= 9; i++) {
        sum += d[n][i];
    }
    cout << sum%mod;
}