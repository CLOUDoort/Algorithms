#include <bits/stdc++.h>
using namespace std;

int N, K, ans = 0;
int s[2][7] = {};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        s[a][b]++;
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 1; j <= 6; j++) {
            ans += (s[i][j]+K-1) / K;
            // if(s[i][j] % K) ++ans;
        }
    }
    cout << ans;
}