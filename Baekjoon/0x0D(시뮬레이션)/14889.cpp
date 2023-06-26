/*
- 조합, 백트래킹 사용
*/

#include <bits/stdc++.h>
using namespace std;

int n; // 짝수
int board[22][22];
int mn = 0x7f7f7f7f; 
int start_sum = 0;
int link_sum = 0;
int start[11], link[11];
bool start_vis[11], link_vis[11];
int s_arr[2], l_arr[2];

void start_func(int k) {
    if(k == 2) {
        start_sum += board[s_arr[0]][s_arr[1]];
        return;
    }
    for(int i = 0; i < n/2; i++) {
        if(start_vis[i]) continue;
        s_arr[k] = start[i];
        start_vis[i] = 1;
        start_func(k+1);
        start_vis[i] = 0;
    }
}

void link_func(int k) {
    if(k == 2) {
        link_sum += board[l_arr[0]][l_arr[1]];
        return;
    }
    for(int i = 0; i < n/2; i++) {
        if(link_vis[i]) continue;
        l_arr[k] = link[i];
        link_vis[i] = 1;
        link_func(k+1);
        link_vis[i] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    vector<int>brute (n, 1);
    fill(brute.begin(), brute.end()-(n/2), 0);
    do {
        // 팀 선택
        for(int i = 0, s_idx = 0, l_idx = 0; i < n; i++) {
            if(brute[i] == 0) start[s_idx++] = i;
            if(brute[i] == 1) link[l_idx++] = i;
        }
        start_sum = 0; link_sum = 0; fill(start_vis, start_vis+11, 0); fill(link_vis, link_vis+11, 0);
        start_func(0); link_func(0);
        mn = min(mn, abs(start_sum-link_sum));
    } while(next_permutation(brute.begin(), brute.end()));
    cout << mn;
}