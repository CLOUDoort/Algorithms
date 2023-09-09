#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<bool> sieve(n+1, true);
    sieve[1] = false;
    for(int i = 2; i <= n; i++) {
        if(!sieve[i]) continue;
        for(int j = i; j <= n; j+=i) {
            if(!sieve[j]) continue;
            sieve[j] = false;
            k--;
            if(k == 0) {
                cout << j;
                return 0;
            }
        }
    }
}