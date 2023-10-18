#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> s;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K, L; cin >> K >> L;
    int a = 0;
    while(L--) {
        string t; cin >> t;
        if(s.find(t) == s.end()) s[t] = a++;
        else {
            s.erase(t);
            s[t] = a++;
        }
    }
    vector<pair<string, int>> v(s.begin(), s.end());
    sort(v.begin(), v.end(), [](pair<string, int>& a, pair<string, int>& b) { return a.second < b.second;});

    int en = min(K, (int)v.size());
    for(int i = 0; i < en; i++) cout << v[i].first << '\n';
}