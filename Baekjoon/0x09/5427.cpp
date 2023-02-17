/*
-아이디어
    - 상하좌우 이동 => BFS 문제
    - string 배열로 입력 받기
    - 열, 행 순으로 입력 주어짐
    - 불 DFS 구하고, 상근이 DFS 구한 뒤에 상근이 탈출 여부 구하기
    - 상근이 BFS 돌릴 때 범위 벗어나면 탈출 성공 판단
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int fire_dist[1002][1002];
int person_dist[1002][1002];
queue<pair<int, int>> FQ;
queue<pair<int, int>> PQ;
int T, n, m;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> m >> n;
        string board[1002];
        int isSuccess = 0;
        for(int i = 0; i < n; i++) {
            cin >> board[i];
            fill(fire_dist[i], fire_dist[i]+m, -1);
            fill(person_dist[i], person_dist[i]+m, -1);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == '@') {
                    PQ.push({i, j});
                    person_dist[i][j] = 0;
                }
                if(board[i][j] == '*') {
                    FQ.push({i, j});
                    fire_dist[i][j] = 0;
                }
            }
        }

        // fire DFS 진행
        while(!FQ.empty()) {
            auto cur = FQ.front(); FQ.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X+dx[dir];
                int ny = cur.Y+dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx][ny] == '#' || fire_dist[nx][ny] >= 0) continue;
                fire_dist[nx][ny] = fire_dist[cur.X][cur.Y]+1;
                FQ.push({nx, ny});
            }
        }

        // 상근이 DFS 진행
        while(!PQ.empty()) {
            auto cur = PQ.front(); PQ.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                // 탈출 성공
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    cout << person_dist[cur.X][cur.Y]+1 << '\n';
                    isSuccess = 1;
                    break;
                }
                if(board[nx][ny] == '#' || person_dist[nx][ny] >= 0) continue;
                if(fire_dist[nx][ny] != -1 && fire_dist[nx][ny] <= person_dist[cur.X][cur.Y]+1) continue;
                person_dist[nx][ny] = person_dist[cur.X][cur.Y]+1;
                PQ.push({nx, ny});
            }
            if(isSuccess) break;
        }

        // 큐 초기화
        while(!PQ.empty()) PQ.pop();

        if(!isSuccess) cout << "IMPOSSIBLE" << '\n';
    }
}