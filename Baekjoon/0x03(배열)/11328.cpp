#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        string a, b;
        int fact = 1;
        int a_arr[26] = {};
        int b_arr[26] = {};
        cin >> a >> b;
        if(a.length() == b.length()) {
            for(int i = 0; i < a.length(); i++) {
                a_arr[a[i]-97]++;
                b_arr[b[i]-97]++;
            }
            for(int i = 0; i < 26; i++) {
                if(a_arr[i] != b_arr[i]) fact = 0;
            }
            if(fact) cout << "Possible \n";
            else cout << "Impossible \n";
        } else cout << "Impossible \n";
    }
}