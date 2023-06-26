#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        stack<char> s;
        string a;
        bool isWrong = false;
        getline(cin, a);
        if(a == ".") break;
        for(auto c : a) {
            if(c == '(' || c == '[') {
                if(c == '(') s.push(')');
                else s.push(']');
            }
            else if(c == ')' || c == ']' ) {
                if(s.empty() || s.top() != c) {
                    isWrong = true;
                    break;
                }
                s.pop(); 
            }
        }
        if(!s.empty()) isWrong = true;
        if(isWrong) cout << "no\n";
        else cout << "yes\n";
    }
}