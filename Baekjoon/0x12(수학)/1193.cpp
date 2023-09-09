#include <bits/stdc++.h>
using namespace std;

int num = 10000000;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, ans = 1; cin >> x;
    pair<int, int> cur = {1, 1};
    bool flag = false;
    if(x == 1) {
        cout << "1/1";
        return 0;
    }
    for(int i = 3; i <= num; i++) {
        for(int j = 1; j < i; j++) {
            if(!flag) cur = {j, abs(i-j)};
            else cur = {abs(i-j), j};
            ans++;
            if(ans == x) {
                cout << cur.first << '/' << cur.second;
                return 0;
            }
        }
        flag = !flag;
    }
}