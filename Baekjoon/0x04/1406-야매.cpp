#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, char b) {
    dat[unused] = b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string N;
    cin >> N;
    for(int i = 0; i < N.length(); i++) {
        dat[unused] = N[i];
        unused++; 
    }
    int cursur = nxt[unused-1];
    int M;
    cin >> M;
    while(M--) {
        char a;
        cin >> a;
        if(a == 'P') {
            char b;
            cin >> b;
            insert(dat[cursur], b);
        }
    }

    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
}