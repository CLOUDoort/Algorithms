#include <bits/stdc++.h>
using namespace std;

int n, a;
int arr[10001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        arr[a]++;
    }
    for(int i = 1; i <= 10000; i++) {
        while(arr[i]--) {
            cout << i << '\n';
        }
    }
}