#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[502][502];
int board[502][502];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int mx, sum;

bool oob(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

void solve(int cx, int cy, int cnt) {
    if(cnt == 4) {
        mx = max(mx, sum);
        return;
    }
    for(int dir = 0; dir < 4; dir++) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        if(oob(nx, ny)) continue;
        if(vis[nx][ny]) continue;
        sum += board[nx][ny];
        vis[nx][ny] = 1;
        solve(nx, ny, cnt+1);
        if(cnt == 2) solve(cx, cy, cnt+1);
        sum -= board[nx][ny];
        vis[nx][ny] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sum = board[i][j];
            vis[i][j] = 1;
            solve(i, j, 1);
            vis[i][j] = 0;
        }
    }
    cout << mx << '\n';
}