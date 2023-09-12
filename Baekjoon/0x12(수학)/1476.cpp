#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int e, s, m; cin >> e >> s >> m;
    if(e == 15) e = 0;
    if(s == 28) s = 0;
    if(m == 19) m = 0;
    for(int i = e; i <= 7980; i+=15) {
        if(i == 0) continue;
        if(i % 28 == s && i % 19 == m) {
            cout << i;
            return 0;
        } 
    }
}