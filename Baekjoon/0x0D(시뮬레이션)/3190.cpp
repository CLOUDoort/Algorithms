#include <bits/stdc++.h>
using namespace std;

int board[101][101], apple[101][101];
int N, K, L, ans;
queue<pair<int, char>>dir_queue;
int dir = 1;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void time_check() {
    int x; char c;
    pair<int, char> cur = dir_queue.front();
    tie(x, c) = cur;
    if(x == ans) {
        if(c == 'L') {
            dir = (dir+3)%4;
            dir_queue.pop();
        }
        else if(c == 'D') {
            dir = (dir+1)%4;
            dir_queue.pop();
        }
    }
}

void input() {
    cin >> N >> K;
    // 사과 놓기
    while(K--) {
        int x, y;
        cin >> x >> y;
        apple[x-1][y-1] = 1;
    }
    cin >> L;
    // 방향 정보 입력
    while(L--) {
        int a; char c;
        cin >> a >> c;
        dir_queue.push({a, c});
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    queue<pair<int, int>> q;
    queue<pair<int, int>> snake;
    q.push({0, 0});
    snake.push({0, 0});
    board[0][0] = 7;
    while(!q.empty()) {
        ans++;
        pair<int, int> cur = q.front(); q.pop();
        int x, y; tie(x, y) = cur;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] == 7) break;
        if(apple[nx][ny]) {
            apple[nx][ny] = 0;
        }
        else {
            int tx, ty;
            pair<int, int> cur = snake.front(); 
            tie(tx, ty) = cur; snake.pop();
            board[tx][ty] = 0;
        }
        q.push({nx, ny});
        snake.push({nx, ny});
        board[nx][ny] = 7;
        time_check();
    }
    cout << ans;
}