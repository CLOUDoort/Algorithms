// 반복문 이분탐색

#include <bits/stdc++.h>
using namespace std;

int n, a[100005];

int BinarySearch(int target) {
    int st = 0, en = n-1;
    while(st <= en) {
        int mid = (st+en)/2;
        if(a[mid] == target) return 1;
        else if(a[mid] > target) en = mid-1;
        else st = mid+1;
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int m; cin >> m;
    sort(a, a+n);
    while(m--) {
        int x; cin >> x;
        cout << BinarySearch(x) << '\n';
    }
}