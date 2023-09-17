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
        if(j % 2 == 0) j /= 2;
        else j = j/2+1;
        if(h % 2 == 0) h /= 2;
        else h = h/2+1;
        n /= 2;
    }
    if(flag) cout << ans;
    else {
        if(j == 1 && h == 2) cout << ans;
        else cout << -1;
    }
}