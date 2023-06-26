#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    queue<int> Q;
    while(N--){
        string q;
        cin >> q;
        if(q == "push") {
            int a;
            cin >> a;
            Q.push(a);
        }
        else if(q == "pop") {
            if(Q.empty()) cout << -1 << '\n';
            else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
        else if(q == "size") {
            cout << Q.size() << '\n';
        }
        else if(q == "empty") {
            if(Q.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(q == "front") {
            if(Q.empty()) cout << -1 << '\n';
            else cout << Q.front() << '\n';
        }
        else {
            if(Q.empty()) cout << -1 << '\n';
            else cout << Q.back() << '\n';
        }
    }
}