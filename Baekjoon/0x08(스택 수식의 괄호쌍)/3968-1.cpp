#include <bits/stdc++.h>
using namespace std;

int ans;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    while(N--){
        string a;
        cin >> a;
        stack<int> s;
        for(auto c : a) {
            if(!s.empty() && s.top() == c) s.pop();
            else s.push(c);
        }
        if(s.empty()) ans++;
    }
    cout << ans;
}