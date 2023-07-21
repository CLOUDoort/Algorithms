/*
    - 테이블 정의
        - d[i] = 처음부터 i보다 작은 증가하는 부분 수열의 가장 긴 길이
*/

#include <bits/stdc++.h>
using namespace std;

int n, a[1005], d[1005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = 1;
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            if(a[i] > a[j]) {
                d[i] = max(d[i], d[j]+1);
            }
        }
    }
    cout << *max_element(d+1, d+n+1);
}