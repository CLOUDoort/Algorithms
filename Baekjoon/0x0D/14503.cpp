#include <bits/stdc++.h>
using namespace std;

int board[52][52];
int n, m, r, c, dir;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool flag;
int ans;

// 주변 4칸 중 청소되지 않은 빈칸 유무 확인
int bfs() {
    for(int d = 0; d < 4; d++) {
        int nx = r + dx[d];
        int ny = c + dy[d];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(!board[nx][ny]) return 1;
    }
    return 0;
}

// 빈칸 있는 경우
void possible() {
    // 반시계방향 회전
    while(1) {
        dir = (dir+3)%4;
        if(dir == 0) {
            if(!board[r-1][c]) {
                r -= 1;
                flag = true;
                return;
            }
        }
        else if(dir == 1) {
            if(!board[r][c+1]) {
                c += 1;
                flag = true;
                return;
            }
        }
        else if(dir == 2) {
            if(!board[r+1][c]) {
                r += 1;
                flag = true;
                return;
            }
        }
        else {
            if(!board[r][c-1]) {
                c -= 1;
                flag = true;
                return;
            }
        }
    }
    
}

// 빈칸 없는 경우
void impossible() {
    // 북쪽 => 남쪽 후진
    if(dir == 0) {
        if(board[r+1][c] != 1) {
            r += 1;
            flag = true;
        }
    }
    // 동쪽 => 서쪽 후진
    else if(dir == 1) {
        if(board[r][c-1] != 1) {
            c -= 1;
            flag = true;
        }
    }
    // 남쪽 => 북쪽 후진
    else if(dir == 2) {
        if(board[r-1][c] != 1) {
            r -= 1;
            flag = true;
        }
    }
    // 서쪽 => 동쪽 후진
    else {
        if(board[r][c+1] != 1) {
            c += 1;
            flag = true;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> r >> c >> dir;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    do {
        flag = false;
        // 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소
        if(!board[r][c]) {
            board[r][c] = 7;
            ans++;
        }
        // 빈칸 유무 확인 경우
        if(bfs()) possible();
        else impossible();
    } while(flag);
    cout << ans;
}