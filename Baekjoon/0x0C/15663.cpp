/*
- 아이디어
    - 중복 허용 x, 순서 있음 => 순열 출력
    - 입력 수 중복
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10], input[10], isUsed[10];

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