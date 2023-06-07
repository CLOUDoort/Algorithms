#include <bits/stdc++.h>
using namespace std;

int n, board[22][22];
int mn = 0x7f7f7f7f;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    vector<int> team(n);
    fill(team.begin()+(n/2), team.end(), 1);
    do {
        int diff = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(team[i] != team[j]) continue;
                if(team[i] == 0) {
                    diff += (board[i][j]+board[j][i]);
                }
                else {
                    diff -= (board[i][j]+board[j][i]);
                }
            }
        }
        mn = min(mn, abs(diff));
    } while(next_permutation(team.begin(), team.end()));
    cout << mn;
}