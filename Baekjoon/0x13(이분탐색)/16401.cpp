#include <bits/stdc++.h>
using namespace std;

int a[1000002], m, n;

bool solve(int x) {
    if(x == 0) return true;
    long long cur = 0;
    for(int i = 0; i < n; i++) cur += a[i]/x;
    return cur >= m;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int st = 0, en = *max_element(a, a+n);
    while(st < en) {
        int mid = (st+en+1)/2;
        if(solve(mid)) st = mid;
        else en = mid-1; 
    }
    cout << st;
}