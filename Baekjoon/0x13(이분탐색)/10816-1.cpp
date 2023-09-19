#include <bits/stdc++.h>
using namespace std;

int n, a[500002];

int lower_idx(int target) {
    int st = 0, en = n;
    while(st < en) {
        int mid = (st+en)/2;
        if(a[mid] >= target) en = mid;
        else st = mid+1;
    }
    return st;
}

int upper_idx(int target) {
    int st = 0, en = n;
    while(st < en) {
        int mid = (st+en)/2;
        if(a[mid] > target) en = mid;
        else st = mid+1;
    }
    return st;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int m; cin >> m;
    while(m--) {
        int x; cin >> x;
        cout << upper_idx(x) - lower_idx(x) << '\n';
    }
}