/*
    이항계수 = 조합의 정의
    nCr = n!/(n-r)!r!
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    int ans = 1;
    for(int i = n; i > n-k; i--) ans *= i;
    for(int i = 1; i <= k; i++) ans /= i;
    cout << ans;
}