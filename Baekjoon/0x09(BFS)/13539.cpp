/*
- 아이디어
    - 수빈이가 시작점부터 갈 수 있는 경우의 수에 최단 거리를 기록하면서 동생을 찾아나선다
    - BFS를 이용한다. 이는 1차원에서의 BFS문제
    - 수빈이의 위치가 100000을 넘을 수 있지만, 최단 거리이기 때문에 넘기는 일은 없다.
- 문제발생
    - 2*X의 경우 이동시간이 증가하지 않기 때문에 최단거리가 아닌 값이 먼저 나올 수 있다.
- 해결방법
    - 2*X를 반복문의 제일 앞에 위치한다.
*/
#include <bits/stdc++.h>
using namespace std;

int n, k;
int dist[200002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    queue<int> Q;
    Q.push(n);
    dist[n] = 1;
    while(dist[k] == 0) {
        int cur = Q.front(); Q.pop();
        for(int next : {cur*2, cur-1, cur+1}) {
            if(next < 0 || next >= 200002) continue;
            if(dist[next] != 0) continue;
            if(next == cur*2) {
                dist[next] = dist[cur];
            } else dist[next] = dist[cur]+1;
            Q.push(next);
        }
    }
    cout << dist[k]-1;
}