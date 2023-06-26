#include <bits/stdc++.h>
using namespace std;

int input, max_value, max_idx;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; i <= 9; i++) {
        cin >> input;
        if(input > max_value) {
            max_value = input;
            max_idx = i;
        }
    }
    cout << max_value << '\n' << max_idx;
}