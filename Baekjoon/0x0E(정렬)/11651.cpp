#include <bits/stdc++.h>
using namespace std;

int n;

bool cmpx(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}
bool cmpy(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    pair<int, int> x[n];
    for(auto& s : x) cin >> s.first >> s.second;
    stable_sort(x, x+n, cmpx);
    stable_sort(x, x+n, cmpy);
    for(auto i : x) cout << i.first << ' ' << i.second << '\n';
}