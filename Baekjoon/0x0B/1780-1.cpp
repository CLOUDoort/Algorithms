/*
- 아이디어
    - N의 최대 크기가 3^7이니 배열을 크기를 2200으로 잡아준다.
    - 처음에 모든 좌표를 돌며 같은 수인지 체크해야 한다.
        - 같은 수이면 해당 번호의 종이 수에 1을 추가해주고 return
        - 다른 수이면 9분할 해서 같은 재귀 실행 
*/

#include <bits/stdc++.h>
using namespace std;

int N;
int paper[2200][2200];
int cnt[3]; // -1: 0, 0 : 1, 1: 2;

bool check(int x, int y, int n) {
    for(int i = x; i < x+n; i++)
    for(int j = y; j < y+n; j++)
        if(paper[x][y] != paper[i][j]) return false;
    return true;
}

void solve(int x, int y, int z) {
    if(check(x, y, z)) {
        cnt[paper[x][y]+1] += 1;
        return;
    }
    // 9등분
    int n = z / 3;
    for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
        solve(x+ i*n, y+ j*n, n);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
        cin >> paper[i][j];
    solve(0, 0, N);
    for(int i = 0; i < 3; i++) cout << cnt[i] << '\n';
}