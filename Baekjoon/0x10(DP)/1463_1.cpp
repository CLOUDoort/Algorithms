#include <bits/stdc++.h>
using namespace std;

int arr[1000005];
int dx[3] = {1, 2, 3};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    arr[1] = 0;
    queue<int> q; q.push(1);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(cur == n) {
            cout << arr[n];
            return 0;
        }
        int nx;
        for(int dir = 0; dir < 3; dir++) {
            if(dir == 0) nx = cur+dx[dir];
            else nx = cur * dx[dir];
            if(nx > n || arr[nx]) continue;
            arr[nx] = arr[cur]+1;
            q.push(nx);
        }
    }
}