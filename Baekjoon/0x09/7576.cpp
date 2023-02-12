/*
- n이 행, m이 열인데, 열 행 순으로 주어짐
- 익은 토마토 좌표를 모조리 큐에 넣고 동시에 BFS 돌린면서 dist 배열에 거리 표시
- board가 -1인 상황은 dist 0으로 방문표시하고 continue, 그럼 -1로 둘러싸인 토마토는 방문 못한 상태니 여전히 -1
- 0의 상하좌우가 -1로 둘러싸인 상태, 모두 익지 못함 => -1 반환
    - BFS를 돌린 다음 dist 배열을 모두 순회하면서 확인 필요
    - -1인 board는 피했기 때문에 -1로 둘러싸인 0은 dist 여전히 -1
    - dist 배열 순회해서 -1이 있으면 -1 반환
    - -1 없으면 dist 배열 중 가장 큰 값 반환
- 0이 없는 상황이라면 => 0 반환
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int board[1002][1002];
int dist[1002][1002];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    queue<pair<int, int>> Q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) Q.push({i, j});
            if(board[i][j] == 0) dist[i][j] = -1;
        }
    }
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            Q.push({nx, ny});
        }
    }
    int mx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
            mx = max(mx, dist[i][j]);
        }
    }
    cout << mx;
}