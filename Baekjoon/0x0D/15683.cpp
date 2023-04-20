/*
- 아이디어
    - 우선 순회하면서 cctv 위치를 모두 확보해야 한다. 6은 벽
    - cctv는 90도 방향으로 회전이 가능하다. => 각 cctv는 총 4번의 경우의 수를 가진다.
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, ans;
int board[10][10], vis[10][10];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool check(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

void bfs(int x, int y) {
    if(check(x, y)) {
        switch(board[x][y]) {
            case 1: {
                for(int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                }
            }
            case 2: {
                
            }
            case 3: {

            }
            case 4: {

            }
            default: {

            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    queue<pair<int, int>> Q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] != 0 || board[i][j] != 6) {
                Q.push({i, j});
                vis[i][j] = 1;
                cnt++;
            }
        }
    }
    while(!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front();
        Q.pop();
        bfs(x, y);
    }
    cout << ((n*m)-cnt);
}