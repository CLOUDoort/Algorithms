/*
- 아이디어
    - 사이클이 존재하고, 사이클 주변에는 사이클로 들어오는 선들이 있는 형태가 된다.
    - O(N^2) 풀이
        - 사이클에 포함된 학생부터 반복문을 돌리게 되면 언젠가는 자기 자신으로 돌아온다.
        사이클에 포함되지 않는 학생은 아무리 해도 자기 자신으로 돌아올 수 없다.
        즉 최초로 방문한 학생이 자기 자신인지 확인하는 과정
        => n번 이내에 자기 자신으로 돌아오는지 확인만 하면 된다.
        - 허나 이 방법은 시간 초과가 날 수 있다.
        - 방문한 노드를 반복해서 방문할 수 있기 때문에 비효율적이다.
    - O(N) 풀이
        - 방문한 노드를 다시 방문하지 않기 위해 방문체크를 넣음 => BFS 활용
        - 풀이
            - 임의의 학생 x에서 시작해 다음 학생으로 계속 이동할 때
            1. 사이클에 포함된 학생 혹은 사이클에 포함되지 않은 학생을 재방문했을 경우 x는 사이클에 포함되지 않은 학생이다. 지금까지 방문한 학생들을 사이클에 포함하지 않은 학생으로 분류한다.
            2. x가 아닌 다른 방문한 학생 y를 재방문했을 경우 x는 사이클에 포함되지 않고 y는 사이클에 포함되어 있다. y에서 출발해 이동하며 다시 y에 도달할 때까지 만나는 학생들을 사이클에 포함된 학생으로 만들고, x에서 출발해 이동하며 y에 도달할 때가지 만나는 학생들을 사이클에 포함되지 않은 학생으로 만든다.
            3. x를 재방문했을 경우 x는 사이클에 포함된 학생이다. x에서 출발해 이동하며 다시 x에 도달할 때까지 만나는 학생들을 사이클에 포함된 학생으로 만든다.
            - 각 학생을 최대 2번 방문하므로 O(N)
            - 풀이 해설 https://blog.encrypted.gg/499#recentEntries
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
        // 이번 방문에서 지나간 학생에 도달했을 경우
        if(state[cur] == x) {
            while(state[cur] != CYCLE_IN) {
                state[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }
        // 이전 방문에서 지나간 학생에 도달했을 경우
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
        // 방문하지 않은 학생들만 run
        for(int i = 1; i <= n; i++) {
            if(state[i] == NOT_VISITED) run(i);
        }
        int cnt = 0;
        // 사이클에 포함되지 않은 학생 수
        for(int i = 1; i <= n; i++) {
            if(state[i] != CYCLE_IN) cnt++;
        }
        cout << cnt << '\n';
    }
}
