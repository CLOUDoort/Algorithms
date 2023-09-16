/*
    - 중복없음, 유일 수 => 조합 사용
*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> a(10, 0);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, cnt = 0; cin >> n;
    for(int i = 1; i <= 10; i++) {
        a[10-i] = 1;
        do {
            if(cnt != n) {
                cnt++;
                continue;
            }
            for(int i = 0; i < 10; i++) {
                if(a[i]) cout << 9-i;
            }
            return 0;
        } while(next_permutation(a.begin(), a.end()));
    }
    cout << -1;
}