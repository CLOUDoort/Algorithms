#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string S;
    cin >> S;
    int cnt = 97;
    vector<int> v1(26);
    for(int i = 0; i < S.length(); i++) {
        for(char a = 'a'; a <= 'z'; a++) if(S[i] == a) v1[a-97]++;
    }
    for(int c : v1 ) cout << c << ' ';

}