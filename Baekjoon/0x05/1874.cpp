#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    stack<int> S;
    vector<char> V;   
    cin >> N;
    int i = 1;
    while(N--) {
        int a;
        cin >> a;
        if(a >= i) {
            for(; i <= a; i++) {
                S.push(i);
                V.push_back('+');
            }
            S.pop();
            V.push_back('-');
        } else {
            if(a == S.top()) {
                S.pop();
                V.push_back('-');
            } 
            else if(a <= S.top()) S.pop();
            else {
                cout << "NO";
                return 0;
            }
        }
    }
    for(char a : V) cout << a << '\n';
}