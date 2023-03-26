/*
- 아이디어
    - 중복 허용하지 않고, 순서가 없는 조합 출력
    - next_permutation 사용한다.
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = m; i < n; i++) arr[i] = 1;
    do {
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) cout << i+1 << ' ';
        }
        cout << '\n';
    } while(next_permutation(arr, arr+n));
}