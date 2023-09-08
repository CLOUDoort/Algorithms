/*
    이항계수 = 조합의 정리
    nCr = n!/(n-r)!r!
    = (n-1)C(r-1)+(n-1)Cr
    해당 식을 가지고 dp를 한다.
    d[i][j] = iCj라 할 때, 
    d[i][j] = d[i-1][j-1]+d[i-1][j]와 같다.
*/

#include <bits/stdc++.h>
using namespace std;

const int mod = 10007;
int d[1002][1002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    for(int i = 1; i <= 1000; i++) {
        d[i][0] = d[i][i] = 1;
        for(int j = 1; j < i; j++) {
            d[i][j] = (d[i-1][j-1]+d[i-1][j])%mod;
        }
    }    
    cout << d[n][k];
}