#include <bits/stdc++.h>
using namespace std;

int arr[100002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        mx = max(mx, i*arr[n-i]);
    }
    cout << mx;
}