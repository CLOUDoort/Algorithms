/*
- 아이디어
    - k개 중에 6개를 고르는 조합
    - next_permutation 사용하기
*/
#include <bits/stdc++.h>
using namespace std;

int k, input[20], arr[20];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        cin >> k;
        if(!k) break;
        for(int i = 0; i < k; i++) { 
            cin >> input[i];
            if(i >= 6) arr[i] = 1;
        }
        do {
            for(int i = 0; i < k; i++) {
                if(!arr[i]) cout << input[i] << ' ';
            }
            cout << '\n';
        } while(next_permutation(arr, arr+k));
        cout << '\n';
    }
}