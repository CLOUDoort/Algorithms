/*
- 아이디어
    - 중복 허락 x, 순서 상관 없는 조합 출력
    - next_permutation 사용
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int idx[10], arr[10];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = m; i < n; i++) idx[i] = 1;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    do {
        for(int i = 0; i < n; i++) {
            if(idx[i] == 0) cout << arr[i] << ' ';
        }
        cout << '\n';
    } while(next_permutation(idx, idx+n));
}