/*
- 아이디어
    - 이동할 수 있는 좌표 8가지 계산, 이동
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[303][303];
int T, N;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i = 0; i < N; i++) fill(board[i], board[i]+N, -1);
        queue<pair<int, int>> Q;
        int a, b, c, d;
        cin >> a >> b;
        cin >> c >> d;
        board[a][b] = 0;
        Q.push({a, b});
        while(board[c][d] == -1) {
            auto cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 8; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if(board[nx][ny] >= 0) continue;
                board[nx][ny] = board[cur.X][cur.Y]+1;
                Q.push({nx, ny});
            }
        }
        cout << board[c][d] << '\n';
    }
}