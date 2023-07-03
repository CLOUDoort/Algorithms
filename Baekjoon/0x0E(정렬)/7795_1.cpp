#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, m, a; cin >> n >> m;
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            cin >> a; v.push_back({a,0});
        }
        for(int i = n; i < n+m; i++) {
            cin >> a; v.push_back({a,1});
        }
        sort(v.begin(), v.end());
        int ans = 0, cnt = 0;
        for(int i = 0; i < n+m; i++) {
            if(!v[i].second) {
                ans += cnt;
            }
            else cnt++;
        }
        cout << ans << '\n';
    }
}