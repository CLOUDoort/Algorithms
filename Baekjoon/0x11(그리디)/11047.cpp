#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[12];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for(int i = n; i > 0; i--) {
        if(a[i] > k) continue;
        ans += k/a[i];
        k %= a[i];
    }
    cout << ans;
}