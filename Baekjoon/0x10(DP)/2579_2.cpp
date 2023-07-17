#include <bits/stdc++.h>
using namespace std;

int s[305], d[305];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i];
    d[1] = s[1];
    if(n > 1) d[2] = s[1] + s[2];
    if(n > 2) d[3] = s[3] + max(s[2], s[1]);
    for(int i = 4; i <= n; i++) {
        d[i] = s[i] + max(s[i-1]+d[i-3], d[i-2]);
    }
    cout << d[n];
}