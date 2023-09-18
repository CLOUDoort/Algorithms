// STL binary_search 함수 사용

#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int m; cin >> m;
    while(m--) {
        int x; cin >> x;
        cout << binary_search(a, a+n, x) << '\n';
    }
}