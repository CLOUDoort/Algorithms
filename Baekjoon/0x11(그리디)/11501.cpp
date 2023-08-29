#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[1000001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int mx = a[n-1];
        ll ans = 0;
        for(int i = n-2; i >= 0; i--) {
            if(a[i] > mx) mx = a[i];
            ans += mx-a[i];
        }
        cout << ans << '\n';
    }
}