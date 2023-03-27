/*
- 아이디어
    - 중복 허용, 비내림차순, 순서 없음 => 조합
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, arr[10], input[10];

void func(int cnt, int cur) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = cur; i < n; i++) {
        arr[cnt] = input[i];
        func(cnt+1, i);
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