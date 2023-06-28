#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    pair<int, int> x[n];
    for(auto&s : x) cin >> s.first >> s.second;
    sort(x, x+n);
    for(auto i : x) cout << i.first << ' ' << i.second << '\n';
}