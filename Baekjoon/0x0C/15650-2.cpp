/*
- 아이디어
    - 중복이 허용되지 않지만, 순서가 없는 수열 => 조합을 구하는 문제
    - 백트래킹 사용
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10], isUsed[10];

void func(int cnt, int cur) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int start = 1+cur;
    for(int i = start; i <= n; i++) {
        if(!isUsed[i]) {
            arr[cnt] = i;
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
    func(0, 0);
}