#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i = 1;
    while(1) {
        int l, p, v, ans = 0;
        cin >> l >> p >> v;
        if(!l) break;
        cout << "Case " << i++ << ": ";
        ans += ((v/p)*l);
        ans += min(v%p, l);
        cout << ans << '\n';
    }
}