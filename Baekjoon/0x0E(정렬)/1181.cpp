#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> a;

bool cmp(const string& a, const string& b) {
    if(a.length() == b.length()) {
        return a < b;
    }
    return a.length() < b.length();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string st; cin >> st;
        a.push_back(st);
    }
    sort(a.begin(), a.end(), cmp);
    // 중복제거
    a.erase(unique(a.begin(), a.end()), a.end());
    for(auto i : a) cout << i << '\n';
}