#include <bits/stdc++.h>
using namespace std;

int a_arr[500002], b_arr[500002];
vector<int> target;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b; cin >> a >> b;
    for(int i = 0; i < a; i++) cin >> a_arr[i];
    for(int i = 0; i < b; i++) cin >> b_arr[i];
    sort(a_arr, a_arr+a); sort(b_arr, b_arr+b);
    for(int i = 0; i < a; i++) {
        if(!binary_search(b_arr, b_arr+b, a_arr[i])) {
            target.push_back(a_arr[i]);
        }
    }
    if(!target.size()) cout << 0;
    else {
        cout << target.size() << '\n';
        for(auto x : target) cout << x << ' ';
    }
}