/*
- 아이디어
    - 크기가 양수인 부분수열 => 1개 이상의 수를 가지는 부분집합 => 2^n-1
*/

#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int arr[30];

void func(int cur, int tot) {
    if(cur == s) {
        if(tot == s) cnt++;
        return;
    }
    func(cur+1, tot);
    func(cur+1, tot+arr[cur]);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];
    func(0, 0);
    if(s == 0) cnt--;
    cout << cnt;
}