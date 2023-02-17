#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string board[1002];
int dist[1002][1002][2];
// dist[x][y][0] : 벽을 하나도 부수지 않고 (x,y)까지 오는데 걸리는 비용
// dist[x][y][1] : 벽을 하나만 부수고 (x,y)까지 오는데 걸리는 비용, (x,y)가 벽이라서 부수는 경우 포함
int n, m;

bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> board[i];
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            dist[i][j][0] = dist[i][j][1] = -1;
    dist[0][0][0] = dist[0][0][1] = 1;
    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});
    while(!Q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = Q.front();
        if(x == n-1 && y == m-1) {
            cout << dist[x][y][broken];
            return 0;
        }
        Q.pop();
        int nextdist = dist[x][y][broken]+1;
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(OOB(nx, ny)) continue;
            if(board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
                dist[nx][ny][broken] = nextdist;
                Q.push({nx, ny, broken});
            }
            if(!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = nextdist;
                Q.push({nx, ny, 1});
            }
        }
    }
    cout << -1;
    return 0;
}
