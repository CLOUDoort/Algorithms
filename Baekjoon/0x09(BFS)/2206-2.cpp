/*
- 아이디어
    - 행,열 순으로 입력
    - string 2차원 배열로 입력 받음
    - 방문자 표시 배열을 벽을 부순 경우와 부수지 않은 경우를 나눈다.
        - 3차원배열에 벽 부순 여부 추가
        - 벽을 부순 경우와 부수지 않은 경우는 완전 다른 세계이다. 완전 독립관계이니 헷갈리면 안된다.
        - 방문자 표시 배열만 3차원 배열로 표시, board와 헷갈리면 안된다.
    - 나눈 것에서 최단거리를 출력한다.
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[1002];
int dist[1002][1002][2];

bool OOB(int a, int b) {
    return a < 0 || a >= n || b < 0 || b >= m;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> board[i];
    queue<tuple<int, int ,int>> Q;

    // 출발지 거리도 포함 => 1로 표시
    dist[0][0][0] = dist[0][0][1] = 1;
    Q.push({0, 0, 0});
    while(!Q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = Q.front();
        // broken 여부와 상관없이 최단거리 출력
        if(x == n-1 && y == m-1) {
            cout << dist[x][y][broken];
            return 0;
        }
        Q.pop();
        // 다음 거리
        int nextdist = dist[x][y][broken]+1;
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(OOB(nx, ny)) continue;
            if(board[nx][ny] == '0' && dist[nx][ny][broken] == 0) {
                dist[nx][ny][broken] = nextdist;
                Q.push({nx, ny, broken});
            }
            if(!broken && board[nx][ny] == '1' && dist[nx][ny][1] == 0) {
                dist[nx][ny][1] = nextdist;
                Q.push({nx, ny, 1});
            }
        }
    }
    cout << -1;
    return 0;
}