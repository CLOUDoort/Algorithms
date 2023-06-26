#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string S;
    cin >> S;
    for(char a = 'a'; a <= 'z'; a++) {
        int cnt = 0;
        for(auto c : S) if(c == a) cnt++;
        cout << cnt << ' ';
    } 
}