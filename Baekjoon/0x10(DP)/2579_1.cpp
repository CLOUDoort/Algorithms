#include <bits/stdc++.h>
using namespace std;

int n;
int d[305], s[305];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        sum += s[i];
    }
    if(n <= 2) {
        cout << sum;
        return 0;
    }
    d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
    for(int i = 4; i <= n-1; i++) {
        d[i] = s[i] + min(d[i-2], d[i-3]);
    }
    cout << sum - min(d[n-1], d[n-2]);
}