/*
    소인수분해
*/

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    // 1을 제외한 n의 가장 작은 약수는 루트n보다 작다는 성질을 이용
    for(int i = 2; i*i <= n; i++) {
        while(n % i == 0) {
            cout << i << '\n';
            n /= i;
        }
    }
    if(n != 1) cout << n;
}