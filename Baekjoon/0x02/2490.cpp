#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string res = "DCBAE";
    int input, result;

    for(int c = 0; c < 3; c++) {
        result = 0;
        for(int r = 0; r < 4; r++) {
            cin >> input;
            result += input;
        }
        cout << res[result] << '\n';
    }
    return 0;

}