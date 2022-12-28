#include <bits/stdc++.h>
using namespace std;

int input, result;
string res = "DCBAE";

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // A : 0111 도 3
    // B : 0011 개 2
    // C : 0001 걸 1
    // D : 0000 윳 0
    // E : 1111 모 4
    for(int r = 0; r < 3; r++) {
        result = 0;
        for(int c = 0; c < 4; c++) {
            cin >> input;
            result += input;
        }
        cout << res[result] << '\n';
    }
    
    
}