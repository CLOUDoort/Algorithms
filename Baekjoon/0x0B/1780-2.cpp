#include <bits/stdc++.h>
using namespace std;

int paper[2200][2200];
int cnt[3];

bool check(int N, int x, int y) {
    for(int i = x; i < x+N; i++) 
        for(int j = y; j < y+N; j++) 
            if(paper[x][y] != paper[i][j]) return false;
    return true;
}

void solve(int N, int x, int y) {
    if(check(N, x, y)) {
        cnt[paper[x][y]+1]++;
        return; 
    }
    int n = N/3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            solve(n, x+n*i, y+n*j);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> paper[i][j];
    solve(N, 0, 0);
    for(int i = 0; i < 3; i++) cout << cnt[i] << '\n';
}