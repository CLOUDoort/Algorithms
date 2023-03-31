/*
- 아이디어
    - 25명 중 7명을 뽑는다.
    - 좌표로 입력 받는다. => 중복 불가능, 근데 순서는 따로 없다 => 조합 => 25개 중, 7개만 0, 나머지는 1로 두고 next_permutation 돌린다.
    - 가로 세로 인접 => BFS 사용
        - x좌표와 y좌표 고려해야 함
        - next_permutation은 1차원 배열 => 여기서 2차원 배열의 x좌표와 y좌표 구할 수 있어야 한다.
    - 4명 이상이 S이어야 한다.
*/
#include <bits/stdc++.h>
using namespace std;

string board[5];
bool mask[25];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 5; i++) cin >> board[i];
    fill(mask+7, mask+25, true);

    do {
        queue<pair<int, int>> Q;
        bool isMark[5][5] = {}, visit[5][5] = {};
        int dasom = 0, total = 0;
        for(int i = 0; i < 25; i++) {
            if(!mask[i]) {
                int x = i / 5; int y = i % 5;
                isMark[x][y] = true;
                if(Q.empty()) {
                    Q.push({x, y});
                    visit[x][y] = true;
                }
            }
        }
        while(!Q.empty()) {
            int x, y;
            tie(x, y) = Q.front();
            Q.pop();
            total++;
            if(board[x][y] == 'S') dasom++;
            for(int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx >= 5 || nx < 0 || ny >= 5 || ny < 0 || !isMark[nx][ny] || visit[nx][ny]) continue;
                Q.push({nx, ny});
                visit[nx][ny] = 1;
            }
        }
        if(total >= 7 && dasom >= 4) ans += 1;
    } while(next_permutation(mask, mask+25));
    cout << ans;
}