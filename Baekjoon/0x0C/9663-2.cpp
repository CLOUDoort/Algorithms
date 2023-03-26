/*
- 아이디어
    - 경우의 수를 잘 따져야 한다.
    - 우선 한 행에는 하나의 퀸만 놓일 수 있다는 것은 바로 알 수 있다.
    - 이외에 3개의 경우의 수를 따져야 한다.
        - 한 열에 하나씩
        - 좌상우하 대각선
        - 우상좌하 대각선
*/

#include <bits/stdc++.h>
using namespace std;

int n, cnt; 
int isUsed1[40]; // 열
int isUsed2[40]; // 좌상우하 대각
int isUsed3[40]; // 우상좌하 대각

void func(int cur) {
    if(cur == n) {
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(isUsed1[i] || isUsed2[cur+i] || isUsed3[cur-i+n-1]) continue;
        isUsed1[i] = 1;
        isUsed2[cur+i] = 1;
        isUsed3[cur-i+n-1] = 1;
        func(cur+1);
        isUsed1[i] = 0;
        isUsed2[cur+i] = 0;
        isUsed3[cur-i+n-1] = 0; 
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}