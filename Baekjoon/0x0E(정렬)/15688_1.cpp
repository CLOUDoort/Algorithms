#include <bits/stdc++.h>
using namespace std;

int arr[2000002];
const int HALF = 1000000;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,t;
    cin >> n;
    while(n--) {
        cin >> t;
        arr[t+HALF]++;
    }
    for(int i = 0; i < 2000002; i++) {
        while(arr[i]--) cout << i-HALF << '\n';
    }
}