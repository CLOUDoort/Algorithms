/*
- 아이디어
    - 중복 허용x, 순서 있는 순열 출력
    - next_permutation 사용
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, arr[10], pre[10];
bool flag;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    do {
        flag = false;
        for(int i = 0; i < m; i++) {
            if(pre[i] != arr[i]) {
                flag = true;
                break;
            }
        }
        if(!flag) continue;
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
            pre[i] = arr[i];
        }
        cout << '\n';
    } while(next_permutation(arr, arr+n));
}