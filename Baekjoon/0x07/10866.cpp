#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    deque<int> DQ;
    while(N--) {
        string q;
        int a;
        cin >> q;
        if(q == "push_front") {
            cin >> a;
            DQ.push_front(a);
        }
        else if(q == "push_back") {
            cin >> a;
            DQ.push_back(a);
        }
        else if(q == "pop_front") {
            if(DQ.empty()) cout << -1 << '\n';
            else {
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }
        }
        else if(q == "pop_back") {
            if(DQ.empty()) cout << -1 << '\n';
            else {
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
        }
        else if(q == "size") {
            cout << DQ.size() << '\n';
        }
        else if(q == "empty") {
            if(DQ.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(q == "front") {
            if(DQ.empty()) cout << -1 << '\n';
            else cout << DQ.front() << '\n';
        }
        else {
            if(DQ.empty()) cout << -1 << '\n';
            else cout << DQ.back() << '\n';
        }
    }
}