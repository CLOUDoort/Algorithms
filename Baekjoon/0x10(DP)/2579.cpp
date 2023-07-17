/*
- 테이블 정의
    - d[i][j] = 현재까지 j개의 계단을 연속해서 밟고 i번째 계단까지 올라섰을 때 점수 합의 최댓값, 단 i번째 계단은 반드시 밟아야 함
    - j는 1 or 2
- 점화식 찾기
- 초기값 정의
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int step[302];
int d[302][3];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> step[i];
    if(n == 1) {
        cout << step[1];
        return 0;
    }
    d[1][1] = step[1]; d[1][2] = 0; 
    d[2][1] = step[2]; d[2][2] = step[1]+step[2];
    for(int i = 3; i <= n; i++) {
        d[i][1] = step[i] + max(d[i-2][1], d[i-2][2]);
        d[i][2] = step[i] + d[i-1][1];
    }
    cout << max(d[n][1], d[n][2]);
}