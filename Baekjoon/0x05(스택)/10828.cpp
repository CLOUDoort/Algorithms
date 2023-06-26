#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    cin >> N;
    while(N--){
        string a;
        cin >> a;
        if(a == "push") {
            int b;
            cin >> b;
            S.push(b);
        }
        else if(a == "pop ") {
            if(S.empty()) cout << -1 << '\n';
            else {
                cout << S.top() << '\n';
                S.pop();
            }
        }
        else if(a == "size") {
            cout << S.size() << '\n';
        }
        else if(a == "empty") {
            cout << (int)S.empty() << '\n';
            // if(S.empty()) cout << 1 << '\n';
            // else cout << 0 << '\n';
        }
        else {
            if(S.empty()) cout << -1 << '\n';
            else cout << S.top() << '\n';
        }
    }
}