#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    queue<int> Q;
    while(N--) {
        string a;
        cin >> a;
        if(a == "push") {
            int b;
            cin >> b;
            Q.push(b);
        }
        else if(a == "pop") {
            if(!Q.empty()) {
                cout << Q.front() << '\n';
                Q.pop();
            } else cout << -1 << '\n';
        }
        else if(a == "size") {
            cout << Q.size() << '\n';
        }
        else if(a == "empty") {
            if(Q.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(a == "front") {
            if(!Q.empty()) cout << Q.front() << '\n';
            else cout << -1 << '\n';
        }
        else {
            if(!Q.empty()) cout << Q.back() << '\n';
            else cout << -1 << '\n';
        }
    }
}