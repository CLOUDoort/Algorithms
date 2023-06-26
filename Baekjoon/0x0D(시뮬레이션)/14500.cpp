#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int board[502][502];

vector<vector<pair<int, int>>> tetro;

// a,b가 상하좌우로 인접한 칸인지 확인하는 함수
// x나 y 둘중에 하나는 무조건 겹쳐야 함
bool isadj(pair<int, int> a, pair<int, int> b) {
    if(a.X == b.X) return abs(a.Y - b.Y) == 1;
    if(a.Y == b.Y) return abs(a.X - b.X) == 1;
    return false;
}


/*
4개의 칸이 연결되어 있는지 확인하는 함수
1. 모든 칸에 대해 상하좌우로 인접한 칸이 존재
2. 2개 이상의 칸과 인접한 칸이 1개라도 있어야 한다.
*/
bool isConn(vector<pair<int, int>>& shape) {
    bool flag = false;
    for(int i = 0; i < 4; i++) {
        int cnt = 0;
        for(int j = 0; j < 4; j++) {
            if(isadj(shape[i], shape[j])) cnt++;
        }
        if(cnt == 0) return false;
        if(cnt >= 2) flag = true;
    }
    return flag;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    vector<int> brute(16);
    fill(brute.begin()+12, brute.end(), 1);
    do {
        vector<pair<int, int>> shape;
        // 16개 중 임의로 4개를 뽑아서 붙어있는지 확인
        for(int i = 0; i < 16; i++) {
            if(brute[i] == 1) {
                shape.push_back({i/4, i%4});
            }
        }
        if(isConn(shape)) tetro.push_back(shape);
    } while(next_permutation(brute.begin(), brute.end()));
    int ans = 0;
    // 기준을 4 by 4로 정했기 때문
    for(int i = 0; i <= n-4; i++) {
        for(int j = 0;  j <= m-4; j++) {
            for(auto shape: tetro) {
                int tot = 0;
                for(auto coor : shape) {
                    tot += board[i+coor.X][j+coor.Y];
                }
                ans = max(tot, ans);
            }
        }
    }
    cout << ans;
}