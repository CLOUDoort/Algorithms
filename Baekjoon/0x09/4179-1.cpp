/*
- 행과 열이 주어지고 string으로 board가 주어진다.
- 불과 지훈이 각각 DFS를 돌린다.
    - 불과 지훈이 DFS 돌리는 것이 서로 상호관계가 있는 것이 아니기 때문에 동시 진행 가능
    - 서로 영향을 끼치는 경우 이 방법 사용 불가
- 시작지점은 0이니 헷갈리지 않게 -1로 fill해준다.
- 지훈이 탈출 암시 상황은 좌표를 벗어나는 상황
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1002];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int fire[1002][1002]; // 불 DFS
int person[1002][1002]; // 지훈 DFS

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        fill(fire[i], fire[i]+m, -1);
        fill(person[i], person[i]+m, -1);
    }
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }
    queue<pair<int, int>> FQ; // 불 좌표
    queue<pair<int, int>> PQ; // 사람 좌표
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'F') {
                FQ.push({i, j});
                fire[i][j] = 0;
            }
            if(board[i][j] == 'J') {
                PQ.push({i, j});
                person[i][j] = 0;
            }
        }
    }

    // 불 전파
    while(!FQ.empty()) {
        auto cur = FQ.front(); FQ.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '#' || fire[nx][ny] >= 0) continue;
            fire[nx][ny] = fire[cur.X][cur.Y]+1;
            FQ.push({nx, ny});
        }
    }

    // 지훈이 이동
    while(!PQ.empty()) {
        auto cur = PQ.front(); PQ.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // 좌표밖으로 나간 경우 탈출 성공 의미
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << person[cur.X][cur.Y]+1;
                return 0;
            }
            if(board[nx][ny] == '#' || person[nx][ny] >= 0) continue;
            // fire은 -1로 fill 해줬기 때문에 구분 필요
            if(fire[nx][ny] != -1 && fire[nx][ny] <= person[cur.X][cur.Y]+1) continue;
            person[nx][ny] = person[cur.X][cur.Y]+1;
            PQ.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}