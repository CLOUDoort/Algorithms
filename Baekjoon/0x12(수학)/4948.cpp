#include <bits/stdc++.h>
using namespace std;

const int num = 123456*2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<bool> state(num+1, true);
    state[1] = false;
    for(int i = 2; i*i <= num; i++) {
        if(!state[i]) continue;
        for(int j = i*i; j <= num; j+=i) {
            state[j] = false;
        }
    }
    while(1) {
        int n, ans = 0; cin >> n;
        if(n == 0) break;
        for(int i = n+1; i <= 2*n; i++) {
            if(state[i]) ans++;
        }
        cout << ans << '\n';
    }
}