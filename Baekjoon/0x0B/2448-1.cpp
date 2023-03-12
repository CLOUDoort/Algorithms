/*
- 함수식
    - 
- base condition
- 재귀식
*/

#include <bits/stdc++.h>
using namespace std;

char DB[][6] = {
    "  *  ",
    " * * ",
    "*****"
};
char board[3100][3100];

void solve(int n, int x, int y) {
    if(n == 1) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 5; j++) {
                board[x+i][y+j] = DB[i][j];
            }
        }
        return;
    }
    solve(n/2, x, y+3*n/2);
    solve(n/2, x+3*n/2, y);
    solve(n/2, x+3*n/2, y+3*n);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    solve(N/3, 0, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 2*N-1; j++) {
            if(board[i][j] == '*') cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}