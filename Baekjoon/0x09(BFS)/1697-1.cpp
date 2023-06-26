/*
- 아이디어
    - 1차원에서 양옆으로만 이동 가능
    - 이동 방법은 x-1, x+1, 2*x으로 3가지 방법
    - 어느 방법으로 이동할 지는 단서는 없고 최단 시간을 구하는 것
    - 그러니 갈 수 있는 모든 곳에 거리 기록
    - DFS 이용
    => 상하좌우로만 DFS를 이용한다는 생각을 깨부순 문제
    - 거리 기록할 배열은 -1로 채워준다
        - 출발점의 거리는 0이기 때문에 다른 것들과 구분하기 위함
- 주의할 점
    - 위치한 점의 범위는 100,000이하지만 100,000을 넘기지 말라는 말은 없다.
    - 하지만 최단거리기 때문에 100,000을 넘기는 일은 없다.
    - 이 문제에 한해서는 범위를 100,000이하로 해도 되지만 다른 문제에서는 꼭 주의하고 넘어가야 한다.
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int dist[100002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    fill(dist, dist+100001, -1);
    queue<int> Q;
    Q.push(n);
    dist[n] = 0;

    while(dist[m] == -1) {
        int cur = Q.front(); Q.pop();
        for(int next : {cur-1, cur+1, cur*2}) {
            if(next < 0 || next > 100000) continue;
            if(dist[next] != -1) continue;
            dist[next] = dist[cur]+1;
            Q.push(next);
        }
    }
    cout << dist[m];
}
