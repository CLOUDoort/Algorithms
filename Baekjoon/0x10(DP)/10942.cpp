/*
- 테이블 정의
    - d[i][j] = i부터 j까지의 팰린드롬 유무
- 점화식 정의
    - 맨앞과 뒤의 숫자가 같아야 함, 그리고 그 사이에 있는 값들은 팰린드롬을 만족시켜야 한다.
*/

#include <bits/stdc++.h>
using namespace std;

int a[2005];
int d[2005][2005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i][i] = 1;
        if(a[i-1]==a[i]) d[i-1][i] = 1;
    }

    for(int gap = 2; gap < n; gap++) {
        for(int i = 1; i <= n-gap; i++) {
            int s = i, e = i+gap;
            if(a[s] == a[e] && d[s+1][e-1]) d[s][e] = 1;
        }
    } 

    cin >> m;
    while(m--) {
        int s, e; cin >> s >> e;
        cout << d[s][e] << '\n';
    }
}