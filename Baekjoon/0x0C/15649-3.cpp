/*
- 아이디어
    - 중복을 허락하지 않는 순열 출력
    - 백트래킹이 아닌 next_permutation 사용할 것
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, flag;
int arr[10], pre[10];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n; i++) arr[i] = i+1;
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
    }while(next_permutation(arr, arr+n));

}