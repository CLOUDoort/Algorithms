#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.X > b.X;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> arr;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        bool check = false;
        for(auto &a : arr) {
            if(a.Y == x) {
                check = true;
                a.X++;
                break;
            }
        }
        if(!check) arr.push_back({1, x});
    }
    stable_sort(arr.begin(), arr.end(), cmp);
    for(auto b : arr) {
        while(b.X--) cout << b.Y << ' ';
    }
}