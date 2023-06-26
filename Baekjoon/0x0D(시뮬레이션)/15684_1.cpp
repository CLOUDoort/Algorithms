/*
- h: 행, n: 열
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m, h;
bool ladder[32][12];
vector<pair<int, int>> line;

bool check() {
    for(int i = 1; i <= n; i++) {
        int tmp = i;
        for(int j = 1; j <= h; j++) {
            if(ladder[j][tmp]) tmp++;
            else if(ladder[j][tmp-1]) tmp--;
        }
        if(tmp != i) return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> h;
    while(m--) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true;
    }
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j < n; j++) {
            if(ladder[i][j-1] || ladder[i][j] || ladder[i][j+1]) continue;
            line.push_back({i, j});
        }
    }
    if(check()) {
        cout << 0;
        return 0;
    }
    
    int ans = 0x7f7f7f7f;
    int sz = line.size();
    for(int i = 0; i < sz; i++) {
        ladder[line[i].X][line[i].Y] = true;
        if(check()) ans = min(ans, 1);
        for(int j = i+1; j < sz; j++) {
            ladder[line[j].X][line[j].Y] = true;
            if(check()) ans = min(ans, 2);
            for(int k = j+1; k < sz; k++) {
                ladder[line[k].X][line[k].Y] = true;
                if(check()) ans = min(ans, 3);
                ladder[line[k].X][line[k].Y] = false;
            }
            ladder[line[j].X][line[j].Y] = false;
        }
        ladder[line[i].X][line[i].Y] = false;
    }
    
    if(ans == 0x7f7f7f7f) ans = -1;
    cout << ans;
}