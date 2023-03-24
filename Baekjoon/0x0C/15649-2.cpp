/*
- 아이디어
    - 중복을 허락하지 않는 순열 출력
    - 수열 담을 배열 설정
    - 중복 체크할 배열 설정
    - 배열의 수가 m개되면 출력
    - 아니면 1~n 까지의 수 중 중복이 안된 수로 배열에 삽입
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[10]; // 수열 담을 배열
int isUsed[10]; // 중복 체크 배열

void func(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!isUsed[i]) {
            arr[cnt] = i;
            isUsed[i] = 1;
            func(cnt+1);
            isUsed[i] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}