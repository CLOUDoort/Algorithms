/*
- string 배열로 받음
- 지훈이와 불의 초기 위치를 각각의 큐에 저장
- 불의 위치 BFS 돌리고 전파 시간 저장
- 지훈이 BFS 돌리고, 탈출 시간 저장할 때 불의 시간이랑 같거나 늦으면 탈출 실패
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1002];
int vis[1002][1002];
int fire[1002][1002];
int r, c;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        fill(vis[i], vis[i]+c, -1);
        fill(fire[i], fire[i]+c, -1);
    }
    queue<pair<int, int>> FQ;
    queue<pair<int, int>> JQ;
    for(int i = 0; i < r; i++) cin >> board[i];
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(board[i][j] == 'F') {
                FQ.push({i, j});
                fire[i][j] = 0;
            }
            if(board[i][j] == 'J') {
                JQ.push({i, j});
                vis[i][j] = 0;
            }
        }
    }
    // 불 전파 DFS
    while(!FQ.empty()) {
        auto cur = FQ.front(); FQ.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny] == '#' || fire[nx][ny] >= 0) continue;
            FQ.push({nx, ny});
            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
        }
    }
    // 지훈이 탈출 BFS
    int ans = 0;
    while(!JQ.empty()) {
        auto cur = JQ.front(); JQ.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) {
                // 범위 벗어났다는 것은 탈출 성공했음을 의미
                cout << vis[cur.X][cur.Y] + 1;
                return 0;
            }
            if(board[nx][ny] == '#' || vis[nx][ny] >= 0) continue;
            if(fire[nx][ny] != -1 && fire[nx][ny] <= vis[cur.X][cur.Y]+1) continue;
            vis[nx][ny] = vis[cur.X][cur.Y]+1;
            JQ.push({nx, ny});
        }
        ans = vis[cur.X][cur.Y];
    }
    cout << "IMPOSSIBLE";
}