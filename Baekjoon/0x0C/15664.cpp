/*
- 아이디어
    - 비내림차순, 중복 허용x, 순서 존재하는 조합 출력
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, input[10], arr[10];

void func(int cnt, int cur) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int start = 0;
    int temp = 0;
    for(int i = cur; i < n; i++) {
        if(temp != input[i]) {
            arr[cnt] = input[i];
            temp = arr[cnt];
            func(cnt+1, i+1);
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