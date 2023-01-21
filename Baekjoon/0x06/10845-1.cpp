#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int a) {
    dat[tail++] = a;
}

void pop() {
    head++;
}

int front() {
    return dat[head];
}

int back() {
    return dat[tail-1];
}

int size() {
    return tail - head;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    while(N--) {
        string a;
        cin >> a;
        if(a == "push") {
            int b;
            cin >> b;
            push(b);
        }
        else if(a == "pop") {
            if(tail == head) cout << -1 << '\n';
            else {
                cout << front() << '\n';
                pop();
            }
        }
        else if(a == "size") {
            cout << tail - head << '\n';
        }
        else if(a == "empty") {
            cout << (tail == head) << '\n';
        }
        else if(a == "front") {
            if(tail == head) cout << -1 << '\n';
            else cout << front() << '\n';
        }
        else {
            if(tail == head) cout << -1 << '\n';
            else cout << back() << '\n';
        }
    }
}