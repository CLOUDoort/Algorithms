/*
- 아이디어
    - BFS를 돌릴 좌표를 찾아야 함(방문했거나 0인 좌표는 무시)
    - BFS 돌릴 좌표 찾으면 BFS 돌리면서 면적 구함
    - 면적은 pop한만큼 ++
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502];
int vis[502][502];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int num = 0;
    int mx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] || board[i][j] != 1) continue;
            queue<pair<int, int>> Q;
            int area = 0;
            num++;
            vis[i][j] = 1;
            Q.push({i, j});
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                area++;
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            mx = max(mx, area);
        }
    }
    cout << num << '\n' << mx;
}