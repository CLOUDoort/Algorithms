/*
- 아이디어
    - 25명 중 7명을 뽑는다.
    - 중복은 없고, 순서도 없다 => 조합 => next_permutation
        - 7명만 0, 나머지는 1로 조합 구현
    - 가로세로 인접 => BFS 이용
*/
#include <bits/stdc++.h>
using namespace std;

string board[5];
bool mark[25];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 5; i++) cin >> board[i];
    fill(mark+7, mark+25, true);

    do {
        queue<pair<int, int>> Q;
        bool isMark[5][5] = {}, visit[5][5] = {};
        int dasom = 0, total = 0;
        for(int i = 0; i < 25; i++) {
            if(!mark[i]) {
                int x = i / 5, y = i % 5;
                isMark[x][y] = 1;
                if(Q.empty()) {
                    Q.push({x, y});
                    visit[x][y] = 1;
                }
            }
        }
        while(!Q.empty()) {
            int x, y;
            tie(x, y) = Q.front();
            Q.pop();
            total++;
            dasom += (board[x][y] == 'S');
            for(int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx >= 5 || nx < 0 || ny >= 5 || ny < 0 || visit[nx][ny] || !isMark[nx][ny]) continue;
                Q.push({nx, ny});
                visit[nx][ny] = 1;
            }
        ans += (total >= 7 && dasom >= 4);
        }
    } while(next_permutation(mark, mark+25));
    cout << ans;
}