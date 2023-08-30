#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ans;
int sarr[1000002], earr[1000002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, st, en; cin >> n;
    for(int i = 0; i < n; i++) cin >> sarr[i] >> earr[i];
    sort(sarr, sarr+n); sort(earr, earr+n);
    st = sarr[0]; en = earr[0];
    for(int i = 1; i < n; i++) {
        if(sarr[i] >= st && sarr[i] <= en) en = earr[i];
        else {
            ans += (en-st);
            st = sarr[i]; en = earr[i];
        }
    }
    ans += (en-st);
    cout << ans;
}