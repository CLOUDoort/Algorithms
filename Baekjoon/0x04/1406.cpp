#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string N; // 초기 입력값
    cin >> N;
    list<char> L;
    for(auto c : N) L.push_back(c);
    auto cur = L.end();
    int M; // 명령어 개수
    cin >> M;

    while(M--) {
        char a;
        cin >> a;
        if(a == 'P') {
            char b;
            cin >> b;
            L.insert(cur, b);
        }
        else if(a == 'L') {
            if(cur != L.begin()) cur--;
        }
        else if(a == 'D') {
            if(cur != L.end()) cur++;
        }
        else {
            if(cur != L.begin()) {
                cur--;
                cur = L.erase(cur);
            }
        }
    }
    for(auto c : L) cout << c;
}