/*
rotate 함수 사용법 숙지
*/

#include <bits/stdc++.h>
using namespace std;

string board[4];
int k, ans;

void check(int num, int clock) {
    int dirs[4] = {};
    dirs[num] = clock;
    int idx = num;
    while(idx > 0 && board[idx][6] != board[idx-1][2]) {
        dirs[idx-1] = -dirs[idx];
        idx--;
    }
    idx = num;
    while(idx < 3 && board[idx][2] != board[idx+1][6]) {
        dirs[idx+1] = -dirs[idx];
        idx++;
    }
    for(int i = 0; i < 4; i++) {
        if(dirs[i] == -1) {
            rotate(board[i].begin(), board[i].begin()+1, board[i].end());
        }
        else if(dirs[i] == 1) {
            rotate(board[i].begin(), board[i].end()-1, board[i].end());
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 4; i++) cin >> board[i];
    cin >> k;
    while(k--) {
        int gear, dir;
        cin >> gear >> dir;
        check(gear-1, dir);
    } 
    for(int i = 0; i < 4; i++) {
        if(board[i][0] == '1') ans += (1 << i);
    }
    cout << ans;
}