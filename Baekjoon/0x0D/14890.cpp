#include <bits/stdc++.h>
using namespace std;

int n,l, board[102][102];
int ans;
vector<pair<int, int>> line;

void row_check(int x, int y) {
    int length = 1;
    int shift = 0;
    for(int i = 0; i < n-1; i++) {
        if(board[x][i] == board[x][i+1]) {
            // 경사로 길이
            if(shift) {
                shift++;
                if(i == n-2) {
                    if(shift < l) return;
                }
            }
            else length++;
        }
        else if(board[x][i] > board[x][i+1]) {
            if(abs(board[x][i]-board[x][i+1]) > 1)  return;
            if(shift) {
                if(shift < l) return;
                shift = 0;
            }
            if(i == n-2) {
                if(shift < l) return;
            }
            length = 1;
            shift = 1;
        }
        else {
            if(abs(board[x][i]-board[x][i+1]) > 1) return;
            if(shift) {
                if(l == 1 && shift == 1) return;
                if(shift < l) return;
                shift = 0;
            }
            if(length < l) return;
            length = 1;
        }
    }
    ans++;
    // cout << "row: (" << x << " " << y << ")\n";
}
void col_check(int x, int y) {
    int length = 1;
    int shift = 0;
    for(int i = 0; i < n-1; i++) {
        if(board[i][y] == board[i+1][y]) {
            // 경사로 길이
            if(shift) {
                shift++;
                if(i == n-2) {
                    if(shift < l) return;
                }
            }
            else length++;
        }
        else if(board[i][y] > board[i+1][y]) {
            if(abs(board[i][y]-board[i+1][y]) > 1)  return;
            if(shift) {
                if(shift < l) return;
                shift = 0;
            }
            length = 1;
            shift = 1;
            if(i == n-2) {
                if(shift < l) return;
            }
        }
        else {
            if(abs(board[i][y]-board[i+1][y]) > 1) return;
            if(shift) {
                if(l == 1 && shift == 1) return;
                if(shift < l) return;
                shift = 0;
            }
            if(length < l) return;
            length = 1;
        }
    }
    ans++;
    // cout << "col: (" << x << " " << y << ")\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        line.push_back({i, 0});
    }
    for(int i = 0; i < n; i++) {
        int x, y; tie(x, y) = line[i];
        row_check(x, y);
        col_check(y, x);
    }
    cout << ans;
}