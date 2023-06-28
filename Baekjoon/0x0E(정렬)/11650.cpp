#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    pair<int, int> x[n];
    for(auto& s : x) cin >> s.first >> s.second;
    stable_sort(x, x+n, [&](pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });
    for(auto i : x) cout << i.first << ' ' << i.second << '\n';
}