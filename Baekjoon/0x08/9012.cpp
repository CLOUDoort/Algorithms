#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--){
       string a;
       stack<char> s;
       bool isWrong = false;
       cin >> a;
       for(auto c : a) {
        if(c == '(') s.push(')');
        else {
            if(s.empty() || s.top() != c) {
                isWrong = true;
                break;
            }
            s.pop();
        }
       }
       if(!s.empty()) isWrong = true;
       if(isWrong) cout << "NO\n";
       else cout << "YES\n";
    }
}