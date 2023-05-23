#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
int board[22][22];
int dice[6];
int tmp[6];

// 주사위 이동
int move(int dir) {
    // 동
    if(dir == 1) {
        if(y+1 >= m) return 1;
        y += 1;
        tmp[3] = dice[5];
        tmp[0] = dice[3];
        tmp[2] = dice[0];
        tmp[5] = dice[2];
    }
    // 서
    else if(dir == 2) {
        if(y-1 < 0) return 1;
        y -= 1;
        tmp[3] = dice[0];
        tmp[0] = dice[2];
        tmp[2] = dice[5];
        tmp[5] = dice[3];
    }
    // 북
    else if(dir == 3) {
        if(x-1 < 0) return 1;
        x -= 1;
        tmp[1] = dice[0];
        tmp[0] = dice[4];
        tmp[4] = dice[5];
        tmp[5] = dice[1];
    }
    // 남
    else {
        if(x+1 >= n) return 1;
        x += 1;
        tmp[1] = dice[5];
        tmp[0] = dice[1];
        tmp[4] = dice[0];
        tmp[5] = dice[4];
    }
    for(int i = 0; i < 6; i++) {
        dice[i] = tmp[i];
    }
    return 0;
}

void check() {
    if(board[x][y] == 0) {
        board[x][y] = dice[5];
    }
    else {
        dice[5] = board[x][y];
        board[x][y] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    while(k--) {
        int d;
        cin >> d;
        if(move(d)) continue;
        check();
        cout << dice[0] << '\n';
    }
}