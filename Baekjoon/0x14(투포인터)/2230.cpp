// 이분탐색
#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int mn = 0x7fffffff;
    for(int i = 0; i < n; i++) {
        int idx = lower_bound(a, a+n, a[i]+m)-a;
        if(idx != n) mn = min(mn, a[idx]-a[i]);
    }
    cout << mn;
}