#include <bits/stdc++.h>
using namespace std;

int a[101];

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        long long ans = 0;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(i == j) continue;
                ans += gcd(a[i], a[j]);
            }
        }
        cout << ans << '\n';
    }
}