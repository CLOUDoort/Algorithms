#include <bits/stdc++.h>
using namespace std;

int n, c;
// 빈도, 순서, 값
vector<tuple<int, int, int>> v;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for(int i = n-1; i >= 0; i--) {
        int a; cin >> a;
        v.push_back({0, i, a});
    }
    for(int i = 0; i < n; i++) {
        int cnt, order, value;
        tie(cnt, order, value) = v[i];
        for(int j = 0; j < n; j++) {
            if(value == get<2>(v[j])) {
                cnt++;
                get<1>(v[j]) = order;
            }
        }
        get<0>(v[i]) = cnt;
    }
    sort(v.begin(), v.end());
    for(int i = n-1; i >= 0; i--) {
        cout << get<2>(v[i]) << ' ';
    }
}