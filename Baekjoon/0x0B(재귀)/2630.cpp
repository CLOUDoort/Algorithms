#include <bits/stdc++.h>
using namespace std;

int N;
int paper[130][130];
int color[2]; // 0은 흰색, 1은 파란색

bool check(int x, int y, int n) {
    for(int i = x; i < x+n; i++)
    for(int j = y; j < y+n; j++) 
        if(paper[x][y] != paper[i][j]) {
            return false;
        }
    return true;
}

void solve(int x, int y, int z) {
    if(check(x, y, z)) {
        color[paper[x][y]] += 1;
        return;
    }
    int n = z / 2;
    for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
        solve(x+i*n, y+j*n, n);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
        cin >> paper[i][j];
    solve(0, 0, N);
    cout << color[0] << '\n' << color[1] << '\n';
}