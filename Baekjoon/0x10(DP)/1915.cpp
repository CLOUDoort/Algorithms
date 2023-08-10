/*
    - 테이블 정의
        - d[i][j] = i,j번째까지의 정사각형 넓이의 최댓값
*/

#include <bits/stdc++.h>
using namespace std;

int d[1005][1005];
int Map[1005][1005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        for(int j = 1; j <= m; j++) {
            Map[i][j] = s[j-1]-'0';
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(Map[i][j]) {
                d[i][j] = min({d[i-1][j-1], d[i][j-1], d[i-1][j]})+1;
                ans = max(ans, d[i][j]);
            }
        }
    }
    cout << ans*ans;
}