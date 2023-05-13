/*
- 치킨 m개를 고르기 => 중복 없고 순서 없는 조합 => Next_permutation 사용하기
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board[55][55];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) chicken.push_back({i, j});
            if(board[i][j] == 1) house.push_back({i, j});
        }
    }
    vector<int> combination(chicken.size(), 1);
    fill(combination.begin(), combination.begin()+chicken.size()-m, 0);
    int mn = 0x7f7f7f7f;
    do {
        int dist = 0;
        for(auto h : house) {
            int tmp = 0x7f7f7f7f;
            for(int i = 0; i < chicken.size(); i++) {
                if(combination[i] == 0) continue;
                tmp = min(tmp, abs(chicken[i].X - h.X) + abs(chicken[i].Y - h.Y));
            }
            dist += tmp;
        }
        mn = min(mn, dist);
    } while(next_permutation(combination.begin(), combination.end()));
    cout << mn;
}