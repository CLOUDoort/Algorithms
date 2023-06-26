#include <bits/stdc++.h>
using namespace std;

int n;
int board1[22][22];
int board2[22][22];

void rotate() {
    int temp[22][22] = {};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp[i][j] = board2[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board2[i][j] = temp[n-1-j][i];
        }
    }
}

void tilted(int dir) {
    while(dir--) rotate();
    for(int i = 0; i < n; i++) {
        int tmp[22] = {};
        int idx = 0;
        for(int j = 0; j < n; j++) {
            if(board2[i][j] == 0) continue;
            if(tmp[idx] == 0) tmp[idx] = board2[i][j];
            else if(tmp[idx] == board2[i][j]) {
                tmp[idx++] *= 2;
            }
            else tmp[++idx] = board2[i][j];
        }
        for(int k = 0; k < n; k++) {
            board2[i][k] = tmp[k];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int value = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board1[i][j];
        }
    }
    for(int tmp = 0; tmp < 1024; tmp++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                board2[i][j] = board1[i][j];
            }
        }
        int brute = tmp;
        for(int i = 0; i < 5; i++) {
            int dir = brute % 4;
            brute /= 4;
            tilted(dir);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                value = max(value, board2[i][j]);
            }
        }
    }
    cout << value << '\n';
}