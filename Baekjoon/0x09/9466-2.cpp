/*
- 아이디어 O(N)
    - 중복을 막기 위해 방문 체크 이용 => BFS 이용
    - 임의의 학생 x에서 시작해 다음 학생으로 계속 이동할 때
    1. 사이클에 포함된 학생 혹은 사이클에 포함되지 않은 학생을 재방문했을 경우 x는 사이클에 포함되지 않은 학생이다. 지금까지 방문한 학생들을 사이클에 포함되지 않은 학생으로 분류한다.
    2. x가 아닌 다른 방문한 학생 y를 재방문했을 경우 x는 사이클에 포함되지 않고 y는 사이클에 포함되어 있다. 다시 y에서 출발해서 y에 도달할 때까지 만나는 학생들을 사이클에 포함되 학생으로 만들고, x에서 출발해 y에 도달할 때까지 만나는 학생들을 사이클에 포함되지 않은 학생들로 만든다.
    3. x를 재방문했을 경우 x는 사이클에 포함된 학생이다. x에서 출발해 이동하며 다시 x에 도달할 떄까지 만나는 학생들을 사이클에 포함된 학생으로 만든다.
    각 학생을 최대 2번 방문하므로 O(N)
*/

#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int n;
int state[100005];

const int NOT_VISITED = 0;
const int VISITED = 1;
const int CYCLE_IN = 2;
const int NOT_CYCLE_IN = 3;

void run(int x) {
    int cur = x;
    while(true) {
        // 방문표시
        state[cur] = VISITED;
        cur = arr[cur];
        // 사이클에 포함된 학생 또는 사이클에 포함되지 않은 학생 만났을 경우 x는 사이클에 포함되지 않음
        if(state[cur] == CYCLE_IN || state[cur] == NOT_CYCLE_IN) {
            // 다시 x로 돌아가서 지금까지 방문한 학생들을 사이클에 포함되지 않은 학생으로 분류한다.
            cur = x;
            while(state[cur] == VISITED) {
                state[cur] = NOT_CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }
        // x가 아닌 다른 방문한 학생 y를 재방문했을 경우 x는 사이클에 포함되지 않고 y는 사이클에 포함되어 있음
        if(state[cur] == VISITED && cur != x) {
            while(state[cur] != CYCLE_IN) {
                state[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            cur = x;
            while(state[cur] != CYCLE_IN) {
                state[cur] = NOT_CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }
        if(state[cur] == VISITED && cur == x) {
            while(state[cur] != CYCLE_IN) {
                state[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }
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
            if(state[i] == NOT_CYCLE_IN) cnt++;
        }
        cout << cnt << '\n';
    }
}