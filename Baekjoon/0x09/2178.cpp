/*
아이디어
1. n, m board 입력받기
    - board 값을 string으로 줌;
    - 입력받은 행 값으로 for문 돌려서 string 받고, board에 넣기
2. BFS를 돌리는데, 시작점은 (0, 0)
3. 시작점으로부터 거리를 저장하는 배열 필요, 새로운 좌표 찾을 떄마다 +1

변수
1. board는 500, 100으로

시간복잡도
한 좌표에 한 번씩만 접근하도록 방문표기 필요
=> dist -1로 초기화한 뒤, 입력 받고, 방문하면 1로 초기화
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[500][100];
int dist[500][100] = {-1};
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    string a;
    for(int i = 0; i < n; i++){
        cin >> a;
        for(int j = 0; j < m; j++) {
            board[i][j] = a[j]-'0';
        }
    }
    queue<pair<int, int>> Q;
    dist[0][0] = 0;
    Q.push({0, 0});
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        int a = 0;
        a += 1;
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] != -1 || board[nx][ny] != 1) continue;
            Q.push({nx, ny});
            dist[nx][ny] = a;
        }
    }
    cout << dist;
}