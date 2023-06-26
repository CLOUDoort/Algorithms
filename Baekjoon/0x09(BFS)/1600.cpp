/*
- 아이디어
    - BFS 활용하는 문제이다.
    - 벽 부수고 이동하기와 체스판 말 이동하기 문제를 합쳐놓은 듯하다.
    - 열, 행 순으로 주어진다.
    - 0,0부터 n-1,m-1까지 이동하는 최단 거리 출력한다.
    - 말처럼 이동할 때는 장애물을 넘을 수 있지만, 그 외에는 장애물을 넘을 수 없다
    - 도착지까지 갈 수 없으면 -1 출력
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int k, n, m;
int board[202][202];
int dist[202][202][32];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int hx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int hy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            fill(dist[i][j], dist[i][j]+31, -1);
        }
    }
    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});
    for(int i = 0; i < k; i++) {
        dist[0][0][i] = 0;
    }
    while(!Q.empty()) {
        int x, y, jump;
        tie(x, y, jump) = Q.front(); 
        if(x == n-1 && y == m-1) {
            cout << dist[x][y][jump];
            return 0;
        }
        Q.pop();
        int nextdist = dist[x][y][jump]+1;
        for(int dir = 0; dir < 4; dir++) {
            int nx = x+dx[dir];
            int ny = y+dy[dir];
            if(OOB(nx, ny)) continue;
            if(board[nx][ny] == 1 || dist[nx][ny][jump] != -1) continue;
            Q.push({nx, ny, jump});
            dist[nx][ny][jump] = nextdist;
        }
        if(jump < k) {
            jump++;
            for(int dir = 0; dir < 8; dir++) {
                int nx = x+hx[dir];
                int ny = y+hy[dir];
                if(OOB(nx, ny)) continue;
                if(board[nx][ny] == 1 || dist[nx][ny][jump] != -1 ) continue;
                dist[nx][ny][jump] = nextdist;
                Q.push({nx, ny, jump});
            }
        }
    }
    cout << -1;
    return 0;
}