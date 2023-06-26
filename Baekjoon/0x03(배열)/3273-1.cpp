#include <bits/stdc++.h>
using namespace std;

int N, X, a[100001], check[2000001] = {}, value = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];

    cin >> X;
    for(int i = 0; i < N; i++) {
        if(X - a[i] > 0 && check[X-a[i]]) value++;
        check[a[i]] = 1;
    }
    cout << value;
}