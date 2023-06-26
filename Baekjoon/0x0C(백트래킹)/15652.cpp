/*
- 아이디어
    - 중복 허용, 비내림차순
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
    int start = 1;
    if(cnt != 0) start = arr[cnt-1];
    for(int i = start; i <= n; i++) {
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