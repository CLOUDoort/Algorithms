#include <bits/stdc++.h>
using namespace std;

#define ll long long

stack<int> s;
int N;
ll ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    ll height;
    while(N--) {
        cin >> height;
        while(!s.empty() && s.top() <= height) s.pop(); 
        ans += s.size();
        s.push(height);
    }
    cout << ans;
    return 0;
}