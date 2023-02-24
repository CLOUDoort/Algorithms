/*
- 아이디어
    - 모든 좌표를 돌면서 방문한 적이 없고 board가 0인 것은 continue
    - 조건에 맞는 것은 큐에 넣고 BFS를 돌린다. 이렇게 쭉 BFS를 돌려서 다음에 넣을 좌표가 없다면 한 덩이리이고, 다시 들어갈 좌표가 있다면 2덩어리 이상임을 알 수 있다.
        - 주변에 0인 좌표를 수를 세어서 melt 배열에 넣어준다
        - 주의할 점은 곧바로 녹이면 안된다는 점이다. 그 다음 좌표에 영향을 주면 안되기 때문이다.
        - 모든 좌표 BFS다 돌린 뒤에 melt가 0이 아닌 좌표들 찾아서 board 값에 melt 값 빼준다.
        이 과정을 반복한다.
    - 그러다가 덩어리가 2개 이상일 경우 year 출력해주고 return
    - 덩어리 하나면 덩어리 다시 초기화
    - 덩어리가 0개면 다 녹아버렸음을 의미하니까 0출력해주고 return 해준다.
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[302][302];
int vis[302][302];
int melt[302][302];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] ={0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    // 분리된 빙산 수
    int ans = 0;
    int year = 0;
    while(true) {
        // 초기화
        for(int i = 0; i < n; i++) {
            fill(vis[i], vis[i]+m, 0);
            fill(melt[i], melt[i]+m, 0);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 0 || vis[i][j] != 0) continue;
                queue<pair<int, int>> Q;
                Q.push({i, j});
                vis[i][j] = 1;
                ans++;
                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    int z_number = 0;
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X+dx[dir];
                        int ny = cur.Y+dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(board[nx][ny] == 0) z_number++;
                        if(vis[nx][ny] != 0 || board[nx][ny] == 0) continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1; 
                    }
                    melt[cur.X][cur.Y] = z_number;
                }
            }
        }
        // BFS가 끝난 뒤에 녹여준다.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(melt[i][j]) {
                    while(melt[i][j]--) {
                        if(board[i][j] <= 0) break;
                        board[i][j]--;
                    }
                }
            }
        }
        if(ans > 1) {
            cout << year;
            return 0;
        }
        else if(ans == 0) {
            cout << 0;
            return 0;
        }
        else {
            ans = 0;
        }
        year++;
    } 
}