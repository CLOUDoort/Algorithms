#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    stack<int> S;
    string ans;
    cin >> N;
    int i = 1;
    while(N--) {
        int a;
        cin >> a;
        while(a >= i) {
            S.push(i++);
            ans += "+\n";
        }
        if(S.top() != a) {
            cout << "NO";
            return 0;
        }
        S.pop();
        ans += "-\n";
    }
    cout << ans;
}