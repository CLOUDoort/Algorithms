/*
- 제일 먼저 익은 토마토의 위치 확인 BFS 돌리기
- 0이 없는 상황이라면 => 0 반환
- 0의 상하좌우가 -1로 둘러싸인 상태, 모두 익지 못함 => -1 반환
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
    cin >> n >> m;
    int z_number = 0;
    for(int i = 0; i < n; i++){
        fill(dist[i], dist[i]+m, -1);
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 0) z_number++;
        }
    }
    // 0이 없으면 익을 토마토도 없음 => 0반환
    if(!z_number) {
        cout << 0;
        return 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            queue<pair<int, int>> Q;
            if(board[i][j] < 1) continue;
            Q.push({i, j});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(board[nx][ny] != 0) continue;
                }
            }
        }
    }
}