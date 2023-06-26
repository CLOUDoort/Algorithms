#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x) {
    dat[pos++] = x;
}

void pop() {
    pos--;
}

int top() {
    return dat[pos-1];
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    while(N--){
        string a;
        cin >> a;
        if(a == "push") {
            int b;
            cin >> b;
            push(b);
        }
        else if(a == "pop") {
            if(pos == 0) cout << -1 << '\n';
            else {
                cout << top() << '\n';
                pop();
            }
        }
        else if(a == "size") {
            cout << pos << '\n';
        }
        else if(a == "empty") {
            cout << (int)(pos == 0) << '\n';
        }
        else {
            if(pos == 0) cout << -1 << '\n';
            else cout << top() << '\n';
        }
    }
}