#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[1000002], n, m;

bool solve(int x) {
    ll cur = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] <= x) continue;
        cur += (a[i]-x);
    }
    return cur >= m;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    int st = 0, en = *max_element(a, a+n);
    while(st < en) {
        int mid = (st+en+1)/2;
        if(solve(mid)) st = mid;
        else en = mid-1;
    }
    cout << st;
}