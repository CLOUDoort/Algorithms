/*
    -테이블 정의
        - d[i] = arr[1] ~ arr[i]까지의 합
    - 점화식 찾기
        - d[i] = arr[i] + d[i-1];
    - 초기값 정의
        - d[1] = arr[1];
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[100005], d[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    d[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        d[i] = d[i-1] + arr[i];
    }
    while(m--) {
        int i, j; cin >> i >> j;
        cout << d[j]-d[i-1] << '\n';
    }
}