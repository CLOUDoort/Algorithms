#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int m, n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, 1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; i < n; j++) {
            cin >> board[i][j];
        }
    }
    
    queue<pair<int, int>> Q;
    vis[0][0] = 1;
    Q.push({0, 0});
}