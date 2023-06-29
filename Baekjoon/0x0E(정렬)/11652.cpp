#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;

bool comp(pair<int, ll> a, pair<int, ll> b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    pair<int, ll> x[n];
    for(auto& s: x) {
        cin >> s.second;
        s.first = 1;
    }
    sort(x, x+n);
    for(int i = 0; i < n; i++) {
        int tmp = i;
        while(1) {
            if(x[tmp].second == x[i+1].second) {
                x[tmp].first++;
                i++;
            }
            else break;
        }
    }
    sort(x, x+n, comp);
    cout << x[n-1].second << '\n';
}