/*
- 아이디어
    - 중복 허용, 순서 있는 수열 출력
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        arr[cnt] = i;
        func(cnt+1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}