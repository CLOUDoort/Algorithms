#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, X, a[1000001], value = 0;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    cin >> X; 
    int arr[2000000] = {};

    for(int i = 0; i < N; i++) {
        if(X >= a[i]) {
            if(arr[X-a[i]]) value++;
            arr[a[i]] = 1;
        } else continue;
    }
    cout << value;
    return 0;
}