#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string S;
    cin >> S;
    // 소문자 97 ~ 122 / 총26개
    vector<int> v1(26);
    for(int i = 0; i < S.length(); i++) {
        for(int j = 97; j < 123; j++) if(S[i] == j) v1[j-97]++;
    }
    for(int i = 0; i < 26; i++) cout << v1[i] << ' ';
}