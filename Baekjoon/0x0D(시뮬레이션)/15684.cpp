/*
h = 행, n = 열, m = 가로선 개수
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m, h;
bool ladder[32][12];
vector<pair<int, int>> coords;

bool check() {
    for(int j = 1; j <= n; j++) {
        int tmp = j;
        for(int k = 1; k <= h; k++) {
            if(ladder[k][tmp]) tmp++;
            else if(ladder[k][tmp-1]) tmp--;
        }
        if(tmp != j) {
            return false;
        }
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
            coords.push_back({i, j});
        }
    }
    if(check()) {
        cout << 0;
        return 0;
    }
    int ans = 0x7f7f7f7f;
    int sz = coords.size();
    for(int i = 0; i < sz; i++) {
        ladder[coords[i].X][coords[i].Y] = true;
        if(check()) ans = min(ans, 1);
        for(int j = i+1; j < sz; j++) {
            ladder[coords[j].X][coords[j].Y] = true;
            if(check()) ans = min(ans, 2);
            for(int k = j+1; k < sz; k++) {
                ladder[coords[k].X][coords[k].Y] = true;
                if(check()) ans = min(ans, 3);
                ladder[coords[k].X][coords[k].Y] = false;
            }
            ladder[coords[j].X][coords[j].Y] = false;
        }
        ladder[coords[i].X][coords[i].Y] = false;
    }
    if(ans == 0x7f7f7f7f) ans = -1;
    cout << ans;
}