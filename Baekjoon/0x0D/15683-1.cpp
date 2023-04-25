#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board1[10][10];
int board2[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>>v;

bool OOB(int a, int b) {
    return a < 0 || a >= n || b < 0 || b >= m;
}

void upd(int x, int y, int dir) {
    dir %= 4;
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if(OOB(x, y) || board2[x][y] == 6) return;
        if(board2[x][y] != 0) continue;
        board2[x][y] = 7;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int mn = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board1[i][j];
            if(board1[i][j] != 0 && board1[i][j] != 6) {
                v.push_back({i, j});
            }
            if(board1[i][j] == 0) mn++;
        }
    }
    for(int tmp = 0; tmp < (1 << (2*v.size())); tmp++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                board2[i][j] = board1[i][j];
            }
        }
        int brute = tmp;
        for(int i = 0; i < v.size(); i++) {
            int dir = brute % 4;
            brute /= 4;
            int x, y; tie(x, y) = v[i];
            if(board1[x][y] == 1) {
                upd(x, y, dir);
            }
            else if(board1[x][y] == 2) {
                upd(x, y, dir);
                upd(x, y, dir+2);
            } 
            else if(board1[x][y] == 3) {
                upd(x, y, dir);
                upd(x, y, dir+1);
            } 
            else if(board1[x][y] == 4) {
                upd(x, y, dir);
                upd(x, y, dir+1);
                upd(x, y, dir+2);
            } 
            else {
                upd(x, y, dir);
                upd(x, y, dir+1);
                upd(x, y, dir+2);
                upd(x, y, dir+3);
            } 
        }
        int value = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                value += (board2[i][j] == 0);
            }
        }
        mn = min(mn, value);
    }
    cout << mn;
}