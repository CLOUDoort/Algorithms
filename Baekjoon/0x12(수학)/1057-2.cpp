#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b; cin >> n >> a >> b;
    if(a > b) swap(a, b);
    for(int i = 1; i <= n; i++) v.push_back(i);
    int ans = 0;
    while(v.size() > 1) {
        ans++;
        vector<int> nxt;
        for(int i = 0; i+1 < v.size(); i += 2) {
            int x = v[i], y = v[i+1];
            if(x == a && y == b) {
                cout << ans;
                return 0;
            }
            if(y == a || y == b) nxt.push_back(y);
            else nxt.push_back(x);
        }
        if(v.size() % 2 == 1) nxt.push_back(v.back());
        v = nxt;
    }
}