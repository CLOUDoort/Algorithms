#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, i;
    cin >> N;
    for(i = 0; i < N-1; i++) {
        int j = 0;
        for( ; j < i; j++) cout << " ";
        for( ; j < 2*N-i-1; j++) cout << "*";
        cout << '\n';
    }
    for(i = 0; i < N-1; i++) cout << " ";
    cout << "*\n";
    for(i = 0; i < N-1; i++) {
        int j = 0;
        for( ; j < N-i-2; j++) cout << " ";
        for( ; j < N+i+1; j++) cout << "*";
        cout << '\n';
    }
}