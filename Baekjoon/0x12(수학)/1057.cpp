#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, j, h, ans = 0; cin >> n >> j >> h;
    if(j > h) swap(j, h);
    bool flag = false;
    while(n) {
        ans++;
        if(j % 2 == 1) {
            if(j+1 == h) {
                flag = true;
                break;
            }
        }
        j = (j+1)/2;
        h = (h+1)/2;
        n /= 2;
    }
    if(flag) cout << ans;
    else {
        if(j == 1 && h == 2) cout << ans;
        else cout << -1;
    }
}