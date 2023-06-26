#include <bits/stdc++.h>
using namespace std;

string board[12];
bool vis[12][6];
bool isPuyo;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int ans;

void resetVis() {
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 6; j++) {
            vis[i][j] = false;
        }
    }
}

void downPuyo() {
    for(int i = 0; i < 6; i++) {
        for(int j = 10; j >= 0; j--) {
            int tmp = j;
            while(tmp < 11 && board[tmp+1][i] == '.') {
                swap(board[tmp][i], board[tmp+1][i]);
                tmp++;
            }
        }
    }
}

void bombPuyo(int x, int y) {
    queue<pair<int, int>>q;
    vector<pair<int, int>>v;
    char color = board[x][y];
    vis[x][y] = true;
    q.push({x, y}); v.push_back({x, y});
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if(nx < 0 || nx >=12 || ny < 0 || ny >= 6) continue;
            if(vis[nx][ny] || board[nx][ny] == '.' || board[nx][ny] != color) continue;
            vis[nx][ny] = true;
            q.push({nx, ny});
            v.push_back({nx, ny});
        }
    }
    if(v.size() >= 4) {
        isPuyo = true;
        for(auto cur : v) {
            board[cur.first][cur.second] = '.';
        }
    }

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 12; i++) {
        cin >> board[i];
    }
    do {
        isPuyo = false;
        downPuyo();
        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 6; j++) {
                if(vis[i][j] || board[i][j] == '.') continue;
                bombPuyo(i, j);
            }
        }
        if(isPuyo) ans++;
        resetVis();
    }
    while(isPuyo);
    cout << ans;
}