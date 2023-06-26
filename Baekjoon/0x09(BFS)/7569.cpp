/*
- 아이디어
    - 3차원 토마토 문제
    - 출발지 여러군데, 동시에 출발
    - 상하좌우 + 위와 아래까지 퍼짐
*/
#include <bits/stdc++.h>
using namespace std;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int board[103][103][103];
int vis[103][103][103];
int n, m, h;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;
    queue<tuple<int, int, int>> Q;
    for(int k = 0; k < h; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int temp;
                cin >> temp;
                board[i][j][k] = temp;
                if(temp == 1) Q.push({i, j, k});
                if(temp == 0) vis[i][j][k] = -1;
            }
        }
    }
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur;
        for(int dir = 0; dir < 6; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if(vis[nx][ny][nz] >= 0) continue;
            vis[nx][ny][nz] = vis[curX][curY][curZ] + 1;
            Q.push({nx, ny, nz});
        }
    }
    int ans = 0;
    for(int k = 0; k < h; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j][k] == -1) {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, vis[i][j][k]);
            }
        }
    }
    cout << ans;
    return 0;
}
