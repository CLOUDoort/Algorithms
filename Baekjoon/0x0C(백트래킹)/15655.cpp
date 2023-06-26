/*
- 아이디어
    - 중복x, 순서x 조합 출력
    - 백트래킹
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, arr[10], isUsed[10], input[10];

void func(int cnt, int cur) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int start = cur;
    for(int i = start; i < n; i++) {
        if(!isUsed[i]) {
            arr[cnt] = input[i];
            isUsed[i] = 1;
            func(cnt+1, i);
            isUsed[i] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> input[i];
    sort(input, input+n);
    func(0, 0);
}