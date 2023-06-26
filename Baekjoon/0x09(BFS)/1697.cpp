/*
- 문제 해석
    - 수빈이와 동생 위치 주어짐(좌표가 아닌 점) => 2차원이 아닌 1차원, 직선의 상황, 양 옆으로만 이동 가능
    - 동생은 고정
    - 수빈이는 걷게 되면 x-1 or x+1, 순간이동하면 2*x
    - 가장 빠른 시간??
- 아이디어
    - 결국은 수빈이의 위치가 동생의 위치와 동일해지면 되는 것이고, 거기까지 가는데 걸리는 시간을 구하는 것
    - 이동할 수 있는 경우의 수에 거리를 기록하는 것
    - BFS를 이용
- 구현 주의할 점
    - board 범위 정할 때 주의 필요, 100000을 넘기지 말라는 의미는 아님, 충분히 넘길 수 있지만, 최단 거리기 때문에 100000을 넘기는 일은 없다.
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[100002];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    fill(board, board+100001, -1);
    board[n] = 0;
    queue<int> Q;
    Q.push(n);
    while(board[m] == -1) {
        int cur = Q.front(); Q.pop();
        for(int nxt : {cur-1, cur+1, 2*cur}) {
            if(nxt < 0 || nxt > 100000) continue;
            if(board[nxt] != -1) continue;
            board[nxt] = board[cur] + 1;
            Q.push(nxt);
        }
    }
    cout << board[m];
}