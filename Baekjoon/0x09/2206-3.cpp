#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
string board[1002];
int vis[1002][1002][2];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> board[i];
    vis[0][0][0] = vis[0][0][1] = 1;
    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});
    while(!Q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = Q.front(); 
        if(x == n-1 && y == m-1) {
            cout << vis[x][y][broken];
            return 0;
        }
        Q.pop();
        int nextvis = vis[x][y][broken]+1;
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '0' && vis[nx][ny][broken] == 0) {
                vis[nx][ny][broken] = nextvis;
                Q.push({nx, ny, broken});
            }
            if(!broken && board[nx][ny] == '1' && vis[nx][ny][1] == 0) {
                vis[nx][ny][1] = nextvis;
                Q.push({nx, ny, 1});
            }
        }
    }
    cout << -1;
    return 0;
}