#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; // the number of test case
    cin >> N;
    while(N--) {
        string s;
        list<char> L;
        cin >> s;
        auto cur = L.begin();
        for(auto c : s) {
            if(c == '<') {
                if(cur != L.begin()) cur--;
            }
            else if(c == '>') {
                if(cur != L.end()) cur++;
            }
            else if(c == '-') {
                if(cur != L.begin()) {
                    cur--;
                    cur = L.erase(cur);
                }
            }
            else {
                L.insert(cur, c);
            }
        }
        for(auto i : L) cout << i;
        cout << '\n';
    }
}