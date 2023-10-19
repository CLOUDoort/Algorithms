#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> memo;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string site, pw; cin >> site >> pw;
        memo[site] = pw;
    }
    while(m--) {
        string a; cin >> a;
        cout << memo[a] << '\n';
    }
}