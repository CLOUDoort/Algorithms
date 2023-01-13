#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    stack<int> S;
    int i = 1;
    string ans;
    while(N--) {
        int a;
        cin >> a;
        while(a >= i) {
            S.push(i++);
            ans += "+\n";
        }
        if(S.top() != a) {
            cout << "NO\n";
            return 0;
        }
        S.pop();
        ans += "-\n";
    }
    cout << ans;
}