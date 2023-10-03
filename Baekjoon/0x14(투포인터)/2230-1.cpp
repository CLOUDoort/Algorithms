// 투포인터

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
    int en = 0;
    for(int st = 0; st < n; st++) {
        while(en < n && a[en] - a[st] < m) en++;
        if(en == n) break;
        mn = min(mn, a[en]-a[st]);
    }
    cout << mn;
}