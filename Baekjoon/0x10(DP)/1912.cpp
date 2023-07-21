/*
    - 직접 비교하고 값을 도출해내기에는 시간이 부족 => DP 사용
    - 테이블 정의
        - d[i] = 처음부터 i를 포함한 몇 개의 수를 더한 가장 큰 값
    - 점화식 찾기
        - 
    - 초기값 찾기
        - d[1] = *max_element(arr+1, arr+n+1);
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
int a[100005];
int d[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i];
    }
    for(int i = 1; i <= n; i++) {
        d[i] = max(d[i], d[i-1]+a[i]);
    }
    cout << *max_element(d+1, d+n+1);
}