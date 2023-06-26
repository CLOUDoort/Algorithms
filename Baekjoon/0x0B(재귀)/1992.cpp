#include <bits/stdc++.h>
using namespace std;

int N;
int board[70][70];

bool check(int x, int y, int n) {
    for(int i = x; i < x+n; i++)
    for(int j = y; j < y+n; j++)
        if(board[x][y] != board[i][j]) return false;
    return true;
}

void solve(int x, int y, int z) {
    if(check(x, y, z)){
        if(z == 1) {
            for(int i = x; i < x+z; i++)
            for(int j = y; j < y+z; j++)
                cout << board[i][j];
                return;
        }
        else {
            cout << board[x][y];
            return;
        }
    }
    cout << '(';
    int n = z / 2;
    for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
        solve(x+i*n, y+j*n, n);
    cout << ')';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            char a;
            cin >> a;
            board[i][j] = a - '0';
        }
    }
    solve(0, 0, N);   
}