#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

pair<int, int> arr[100002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        arr[i] = {b, a};
    }
    sort(arr+1, arr+n+1);
    int ans = 1;
    int endTime = arr[1].X;
    for(int i = 2; i <= n; i++) {
        if(endTime > arr[i].Y) continue;
        ans++; endTime = arr[i].X;
    }
    cout << ans;
}