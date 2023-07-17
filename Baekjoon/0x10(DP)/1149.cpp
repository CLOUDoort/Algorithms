/*
- 테이블 정의
    - d[i][0] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 빨강
    - d[i][1] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 초록
    - d[i][2] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 파랑
- 점화식 찾기
    - d[i][0] = min(d[i-1][1], d[i-1][2]) + color[i][0];
    - d[i][1] = min(d[i-1][0], d[i-1][2]) + color[i][1];
    - d[i][2] = min(d[i-1][0], d[i-1][1]) + color[i][2];
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
int color[1002][3];
int d[1002][3];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> color[i][0] >> color[i][1] >> color[i][2];
    }
    d[1][0] = color[1][0];
    d[1][1] = color[1][1];
    d[1][2] = color[1][2];
    for(int i = 2; i <= n; i++) {
        d[i][0] = min(d[i-1][1], d[i-1][2]) + color[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + color[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + color[i][2];
    }
    cout << min({d[n][0], d[n][1], d[n][2]});
}