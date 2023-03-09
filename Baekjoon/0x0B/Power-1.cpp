#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll func1(ll a, ll b, ll m) {
    ll val = 1;
    while(b--) val = val * a % m;
    return val;
}

int main(void) {
    cout << func1(6, 100, 5);
}