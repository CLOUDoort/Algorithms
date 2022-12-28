#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int input, sum = 0, min_number = 10000;
    for(int i = 0; i < 7; i++) {
        cin >> input;
        if(input % 2 != 0) {
            sum += input;
            if(input < min_number) min_number = input;
        }
    }
    if(sum == 0) cout << -1;
    else cout << sum << '\n' << min_number;
}