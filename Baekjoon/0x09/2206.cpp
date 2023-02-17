/*
- 아이디어
    - string으로 받음, 행, 열 순으로 입력
    - (1,1)부터 시작, 시작거리부터 1로 시작해야 함
    - 벽 한 개까지 부술 수 있음, 최단거리 구하기
    - 탈출 못하면 -1 반환
-실패
    - 벽을 부수지 않을 때와 부술 때의 여부를 3차원배열에 추가할 생각 전혀 못했음
    - 
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long

ll board[1002][1002];
int dist[1002][1002];
int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            char a;
            cin >> a;
            board[i][j] = a - '0';
        }
    }
    queue<pair<int, int>> Q;
    dist[0][0] = 1;
    Q.push({0,0});
    int one_shot = 1;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(dist[nx][ny] > 0 || board[nx][ny] == 1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            Q.push({nx, ny});
        }
        if(Q.empty() && one_shot) {
            for(int dirx = 0; dirx < 4; dirx++) {
                int nx = cur.X + dx[dirx];
                int ny = cur.Y + dy[dirx];
                for(int dir = 0; dir < 4; dir++) {
                    int px = nx + dx[dir];
                    int py = ny + dy[dir];
                    if(px < 0 || px >= N || py < 0 || py >= M) continue;
                    if(dist[px][py] > 0 || board[px][py] == 1) continue;
                    dist[nx][ny] = dist[cur.X][cur.Y]+1;
                    dist[px][py] = dist[nx][ny]+1;
                    Q.push({px, py});
                    one_shot = 0;
                }
            }
        }
        if(dist[N-1][M-1]) {
            cout << dist[N-1][M-1];
            return 0;
        }
    }
    cout << -1;
    return 0;
}