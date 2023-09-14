#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        ll x, y; cin >> x >> y;
        ll dis = y-x, move = 0, n = 0;
        while(n*n <= dis) n++;
        n--;
        move = 2*n-1;
        ll rem = dis-(n*n);
        move += (ll)ceil((double)rem/(double)n);
        cout << move << '\n';
    }
}