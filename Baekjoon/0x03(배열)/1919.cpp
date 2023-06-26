#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    int a[26] = {}, value = 0;
    cin >> s1 >> s2;
    for(char c : s1) a[c-'a']++;
    for(char c : s2) a[c-'a']--;
    
    for(int i : a) if(i != 0) value += abs(i);
    cout << value;
}