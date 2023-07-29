#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, i = 0; cin >> t;
    while(t--) {
        i++;
        cout << "Case #" << i << '\n';
        int n, a, b, box = 0;
        cin >> n >> a >> b;
        int mn = min(a, b), mx = max(a, b);
        if(n%mn == 0) {
            cout << n / mn << '\n';
        }
        else {
            while(n) {
                box++;
                n -= mx;
                if(n%mn == 0) {
                    cout << box+n/mn << '\n';
                    break;
                }
            }
        }
    }
}