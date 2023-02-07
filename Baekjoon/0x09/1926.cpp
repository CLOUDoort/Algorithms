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
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    int mx = 0;
    int num = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int area = 0;
            if(vis[i][j] || board[i][j] == 0) continue;
            queue<pair<int, int>> Q;
            // BFS 시작지점
            vis[i][j] = 1;
            Q.push({i, j});
            num++;
            // BFS 돌리기
            while(!Q.empty()){
                // pop이 이루어질 때마다 area++
                area++;
                pair<int, int> cur = Q.front(); Q.pop();
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

/*
- 아이디어
    - DFS 사용
    - board 전부 다 돌아야함 => 이중for문
    - 이중 for문을 통해 BFS 돌릴 좌표 찾고 BFS돌리기, 그림 개수++
    - DFS돌릴 때 그림 넓이 구하기, 그림 넓이 최댓값은 DFS 돌릴 떄마다 max돌리기
*/