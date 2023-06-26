#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll ans = 0;
stack<char> st;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') st.push(s[i]);
        else {
            if(s[i-1] == '(') {
                st.pop();
                ans += st.size();
            }
            else {
                st.pop();
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}