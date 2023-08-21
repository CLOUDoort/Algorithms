#include <bits/stdc++.h>
using namespace std;

int t[1002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> t[i];
    sort(t+1, t+n+1);
    int sum = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        sum += t[i];
        ans += sum;
    }
    cout << ans;
}