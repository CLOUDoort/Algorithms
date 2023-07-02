#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll arr[1000001];

ll invert(ll a) {
    string tmp = to_string(a);
    string tmp_a = to_string(a);
    for(int i = 0; i < tmp.length(); i++) {
        tmp[i] = tmp_a[tmp.length()-1-i];
    }
    return stoll(tmp);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll a; cin >> a;
        arr[i] = invert(a);
    }
    sort(arr, arr+n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
}