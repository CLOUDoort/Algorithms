/*
-아이디어
    - BFS를 활용한다.
    - 각 섬의 좌표에 번호를 부여하여 BFS로 순회하면서 섬을 구분한다. 1번섬, 2번섬, 3번섬...
    - 각 섬의 좌표를 모두 큐에 넣고, 다른 섬과 접촉하는 최소거리 구하면 끝
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
int board[103][103];
int vis[103][103];
int dist[103][103];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    // 섬 숫자 부여하여 구분
    int value = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 0 || vis[i][j]) continue;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            value++;
            board[i][j] = value;
            vis[i][j] = 1;
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] == 0 || vis[nx][ny]) continue;
                    board[nx][ny] = value;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    int ans = 1000;
    for(int num = 1; num <= value; num++) {
        queue<pair<int, int>> Q;
        for(int i = 0; i < n; i++) {
            fill(dist[i], dist[i]+n, -1);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == num) {
                    Q.push({i, j});
                    dist[i][j] = 0;
                }   
            }
        }
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            if(board[cur.X][cur.Y] != 0 && board[cur.X][cur.Y] != num) {
                ans = min(ans, dist[cur.X][cur.Y]-1);
            }
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[cur.X][cur.Y]+1;
                Q.push({nx, ny});
            }
        }
    }
    cout << ans;
}