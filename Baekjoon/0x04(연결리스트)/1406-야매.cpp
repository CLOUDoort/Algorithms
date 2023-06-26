#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, char c) {
    dat[unused] = c;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
    // 메모리 해제가 안됨
}

void traversal() {
    int cur = nxt[0];
    while(cur != -1) {
        cout << dat[cur];
        cur = nxt[cur];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    string N;
    cin >> N;
    int cursor = 0;
    for(auto c : N) {
        insert(cursor, c);
        cursor++;
    }
    int M;
    cin >> M;
    while(M--) {
        char a;
        cin >> a;
        if(a == 'P') {
            char b;
            cin >> b;
            insert(cursor, b);
            cursor = nxt[cursor];
        }
        else if(a == 'L') {
            if(pre[cursor] != -1)  {
                cursor = pre[cursor];
            }
        }
        else if(a == 'D') {
            if(nxt[cursor] != -1) {
                cursor = nxt[cursor];
            }
        }
        else {
            if(pre[cursor] != -1) {
                erase(cursor);
                cursor = pre[cursor];
            }
        }
    }
    traversal();
}