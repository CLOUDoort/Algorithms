#include <bits/stdc++.h>
using namespace std;

int a[20000002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        a[t+10000000]++;
    }
    int m; cin >> m;
    while(m--) {
        int x; cin >> x;
        cout << a[x+10000000] << '\n';
    }
}