/*
- h: 행, n: 열
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, h;
bool ladder[32][12];
bool temp[32][12];
vector<pair<int, int>> line;
void reset() {
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= n; j++) {
            temp[i][j] = ladder[i][j];
        }
    }
}

bool check() {
    for(int i = 1; i <= n; i++) {
        int tmp = i;
        for(int j = 1; j <= h; j++) {
            if(temp[j][tmp]) tmp++;
            else if(temp[j][tmp-1]) tmp--;
        }
        if(tmp != i) return false;
    }
    return true;
}

int test(int cnt) {
    vector<int> brute(line.size(), 1);
    fill(brute.begin(), brute.end()-cnt, 0);
    do {
        for(int i = 0; i < line.size(); i++) {
            if(brute[i]) {
                temp[line[i].first][line[i].second] = 1;
            }
        }
        if(check()) {
            return cnt;
        }
        reset();
    } while(next_permutation(brute.begin(), brute.end()));
    return 0x7f7f7f7f;
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
            if(ladder[i][j] || ladder[i][j-1] || ladder[i][j+1]) continue;
            line.push_back({i, j});
        }
    }
    reset();
    if(check()) {
        cout << 0;
        return 0;
    }
    int ans = 0x7f7f7f7f;
    for(int i = 1; i <= 3; i++) {
        ans = min(ans, test(i));
    }
    if(ans == 0x7f7f7f7f) ans = -1;
    cout << ans;
}