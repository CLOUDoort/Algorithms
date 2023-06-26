#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string S;
    cin >> S;
    vector<int> v1(26);
    for(auto c : S) v1[c-'a']++;
    for(int c : v1) cout << c << ' ';
}