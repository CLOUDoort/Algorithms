#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll func1(ll a, ll b, ll m) {
    ll val = 1;
    // 곱하는 중간 중간 계속 m으로 나눠서 나머지만 챙겨준다.
    // 시간복잡도는 O(b)
    while(b--) val  = val * a % m;
    return val;
}

int main(void) {
    cout << func1(6, 100, 5) << '\n';
}