#include <bits/stdc++.h>
using namespace std;

int freq[26]; // 0으로 초기화
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string S;
    cin >> S;
    for(auto c : S) freq[c-'a']++;
    for(int i = 0; i < 26; i++) cout << freq[i] << ' ';
}