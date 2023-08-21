#include <bits/stdc++.h>
using namespace std;

int n, m, l;
int v[51];

bool solve(int x) {
    int must_cnt = 0;
    int pre = 0;
    for(int i = 0; i <= n; i++) {
        int dist = v[i] - pre;
        if(dist >= x) {
            if(dist % x != 0) must_cnt += dist / x;
            else must_cnt += (dist / x-1);
        }
        pre = v[i];
    }
    if(must_cnt > m) return true;
    else return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> l;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v, v+n);
    v[n] = l;

    int st = 1, en = l;
    while(st < en) {
        int mid = (st+en)/2;
        if(solve(mid)) st = mid+1;
        else en = mid;
    }
    cout << st;
    return 0;
}