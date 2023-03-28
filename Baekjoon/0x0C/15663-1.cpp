/*
- 아이디어
    - 중복 허용 안됨, 순서 있는 순열 출력
    - 입력에 중복된 숫자 있음, 이를 방지해야 함
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, input[10], arr[10], isUsed[10];

void func(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int temp = 0;
    for(int i = 0; i < n; i++) {
        if(!isUsed[i] && temp != input[i]) {
            arr[cnt] = input[i];
            isUsed[i] = 1;
            temp = arr[cnt];
            func(cnt+1);
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
    func(0);
}