#include <bits/stdc++.h>
using namespace std;

long long fibo(int n) {
    if(n <= 1) return 1;
    return fibo(n-1) + fibo(n-2);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fibo(10) << '\n';
    return 0;
}