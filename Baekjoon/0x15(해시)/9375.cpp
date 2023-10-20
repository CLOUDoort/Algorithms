#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, ans = 1; cin >> n;
        string name, cate;
        unordered_map<string, int> clothings;
        while(n--) {
            cin >> name >> cate;
            clothings[cate]++;
        }
        for(auto a : clothings) ans *= a.second+1;
        cout << ans-1 << '\n';
    }
}