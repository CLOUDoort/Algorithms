#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N;
ll h, ans = 0;
stack<int> s;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    while(N--) {
        cin >> h;
        while(!s.empty() && s.top() <= h) s.pop();
        ans += s.size();
        s.push(h);
    }
    cout << ans;
}