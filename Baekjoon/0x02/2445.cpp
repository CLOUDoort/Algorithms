#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N-1; i++) {
        int j;
        for(j = 0; j<i+1; j++) cout << "*";
        for(j = 0; j<2*(N-1-i); j++) cout << " ";
        for(j = 0; j<i+1; j++) cout << "*";
        cout << '\n';
    }
    for(int i = 0; i < 2*N; i++) cout << "*";
    cout << '\n';
    for(int i = 0; i < N-1; i++) {
        int j;
        for(j = 0; j < N-i-1; j++) cout << "*";
        for(j = 0; j < 2*(i+1); j++) cout << " ";
        for(j = 0; j < N-i-1; j++) cout << "*";
        cout << '\n';
    }
}