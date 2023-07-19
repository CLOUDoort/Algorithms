#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int t, n;
pair<int, int> f[41];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    f[0] = {1, 0}; f[1] = {0, 1};
    for(int i = 2; i <= 40; i++) {
        f[i] = { f[i-1].X+f[i-2].X, f[i-1].Y+f[i-2].Y};
    }
    while(t--) {
        cin >> n;
        cout << f[n].X << ' ' << f[n].Y << '\n';
    }
}