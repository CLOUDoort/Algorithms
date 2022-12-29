#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int j = 0;
        for( ; j < N-i-1; j++) cout << " ";
        for( ; j < N+i; j++) cout << "*";
        cout << '\n';
    }
    for(int i = 0; i < N-1; i++) {
        int j = 0;
        for( ; j < i+1; j++) cout << " ";
        for( ; j < 2*(N-1)-i; j++) cout << "*";
        cout << '\n';
    }
}