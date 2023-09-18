// 재귀 이분탐색

#include <bits/stdc++.h>
using namespace std;

int a[100002];

int BinarySearch(int st, int en, int target) {
    if(st > en) return 0;
    int mid = (st+en)/2;
    if(a[mid] == target) return 1;
    else if(a[mid] > target) {
        return BinarySearch(st, mid-1, target);
    }
    else return BinarySearch(mid+1, en, target);
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int m; cin >> m;
    while(m--) {
        int x; cin >> x;
        cout << BinarySearch(0, n-1, x) << '\n';
    }
}