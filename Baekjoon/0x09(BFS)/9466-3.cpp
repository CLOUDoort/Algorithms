/*
- 아이디어
    - BFS를 여러 시작점에 대해 진행해야 할 때 visited 배열을 매번 서로 만들거나 초기화를 시키면 O(N^2)이 되지만 visited 여부를 체크하는 값을 매번 다른 값을 넣어 O(N)으로 만드는 테크닉 숙지하기
*/

#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int n;
int state[100005];

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void run(int x) {
    int cur = x;
    while(true) {
        state[cur] = x;
        cur = arr[cur];
        // 이번 방문에서 도달
        if(state[cur] == x) {
            while(state[cur] != CYCLE_IN) {
                state[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }
        // 이전 방문
        else if(state[cur] != 0) return;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        fill(state+1, state+n+1, 0);
        for(int i = 1; i <= n; i++) cin >> arr[i];
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(state[i] == NOT_VISITED) run(i);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(state[i] != CYCLE_IN) cnt++;
        }
        cout << cnt << '\n';
    }
}