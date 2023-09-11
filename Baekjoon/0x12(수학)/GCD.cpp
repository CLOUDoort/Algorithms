/*
    GCD = Greatest Common Divisor(최대 공약수)
    시간복잡도는 O(log(max(a, b)))
*/
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(a%b, a);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b; cin >> a >> b;
    cout << gcd(a, b);
}