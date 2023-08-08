#include <bits/stdc++.h>
using namespace std;

int coin[22], m;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, d[10002] = {0, };
        cin >> n;
        for(int i = 0; i < n; i++) cin >> coin[i];
        cin >> m;
        d[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = coin[i]; j <= m; j++) {
                d[j] += d[j - coin[i]];
            }
        }
        cout << d[m] << '\n';
    } 
}