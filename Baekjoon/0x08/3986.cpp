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
        stack<char> s;
        if(a.length() % 2 == 0) {
            for(char c : a) {
                if(s.empty()) s.push(c);
                else {
                    if(s.top() == c) s.pop();
                    else s.push(c);
                }
            }
        if(s.empty()) ans++;
        }
    }
    cout << ans;
}