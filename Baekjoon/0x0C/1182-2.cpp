/*
- 아이디어
    - 크기가 양수인 부분수열 => 1개 이상의 집합 => 2^n-1개
    - 값을 더할지 말지 2가자의 경우의 수를 두고 재귀 함수를 돌린다.
*/

#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int arr[30];

void func(int sum, int cur) {
    if(cur == n) {
        if(sum == s) cnt++;
        return;
    }
    func(sum, cur+1);
    func(sum+arr[cur], cur+1);
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