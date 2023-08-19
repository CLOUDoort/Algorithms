#include <bits/stdc++.h>
using namespace std;

int a[1002], btw[502];
bool comp(int a, int b) {
    return a > b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, l; cin >> n >> m >> l;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        a[t]++;
    }
    int x = 0, y = 0, idx = 1, st = 0;
    for(int i = 1; i <= l; i++) {
        if(!a[i]) continue;
        if(!x) {
            st = i;
            x = i;
        }
        else if(!y) y = i;
        if(x && y) {
            btw[idx++] = y-x; 
            x = y; y = 0;
        }
    }
    btw[0] = st;
    btw[idx] = l-x;
    sort(btw, btw+idx+1, comp);
    if(m == 1) cout << btw[1]/2+1;
    else cout << btw[1]/(m-idx+2);
}