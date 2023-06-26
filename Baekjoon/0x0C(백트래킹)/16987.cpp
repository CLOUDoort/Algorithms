/*
- 아이디어
    - 내구도는 무게만큼 깎인다.
    - 내구도가 0이 되면 깨진다.
    - 제일 왼쪽에 있는 계란을 들어 손에 든 계란이 깨지거나, 계란이 깨지지 않으면 다음 계란으로 넘어간다.
        - 즉 깨질 때까지 친다. => DFS 사용
*/
#include <bits/stdc++.h>
using namespace std;
int n;
int s[10], w[10];
int mx = 0;
int cnt = 0; // 깨져있는 계란의 수

void solve(int a) {
    if(a == n) {
        mx = max(mx, cnt);
        return;
    }
    if(s[a] <= 0 || cnt == n-1) {
        solve(a+1);
        return;
    }
    for(int t = 0; t < n; t++) {
        if(t == a or s[t] <= 0) continue;
        s[a] -= w[t];
        s[t] -= w[a];
        if(s[a] <= 0) cnt++;
        if(s[t] <= 0) cnt++;
        solve(a+1);
        if(s[a] <= 0) cnt-- ;
        if(s[t] <= 0) cnt--;
        s[a] += w[t];
        s[t] += w[a];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i] >> w[i];
    solve(0);
    cout << mx;
}