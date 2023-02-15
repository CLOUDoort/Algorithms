/*
- 아이디어
    - 입력값은 string 배열로 받는다.
    - 색약이 없는 사람의 DFS 돌리는 횟수
    - R과 G를 구분하지 못하는 사람의 DFS 돌리는 횟수
        - R이나 G일 경우 B만 continue
        - B일 경우 모두 continue
*/

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int N;
string board[101];
int vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> board[i];
    queue<pair<int, int>> Q;

    // 색약 없는 사람
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(vis[i][j]) continue;
            Q.push({i, j});
            vis[i][j] = 1;
            ans++;
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                char color = board[cur.X][cur.Y];
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X+dx[dir];
                    int ny = cur.Y+dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(vis[nx][ny] || board[nx][ny] != color) continue;
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    cout << ans;

    // 다시 초기화
    ans = 0;
    for(int i = 0; i < N; i++) fill(vis[i], vis[i]+N, 0);
    // 적록색약 있는 사람
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(vis[i][j]) continue;
            Q.push({i, j});
            vis[i][j] = 1;
            ans++;
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                char color = board[cur.X][cur.Y];
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X+dx[dir];
                    int ny = cur.Y+dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(color == 'B') {
                        if(vis[nx][ny] || board[nx][ny] != color) continue;
                    } else {
                        if(vis[nx][ny] || board[nx][ny] == 'B') continue;
                    }
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    cout << " " << ans;
}
