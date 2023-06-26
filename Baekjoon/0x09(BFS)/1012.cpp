/*
- 아이디어
    - 배추흰지렁이 상하좌우 이동 => BFS 활용
    - 배추 위치 입력받기
    - BFS 돌릴 위치 찾고, BFS를 돌리는 횟수가 배추 흰지렁이의 개수가 된다.

*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int T, n, m, num;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;

    while(T--) {
        cin >> n >> m >> num;
        int board[52][52] = {0};
        int vis[52][52] = {0};
        queue<pair<int, int>> Q;
        for(int i = 0; i < num; i++) {
            int a, b;
            cin >> a >> b;
            board[a][b] = 1;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] != 1 || vis[i][j]) continue;
                Q.push({i, j});
                vis[i][j] = 1;
                ans++;
                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(board[nx][ny] != 1 || vis[nx][ny]) continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}