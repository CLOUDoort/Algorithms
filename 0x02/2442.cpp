#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int j = 0;
        for( ; j<N-1-i; j++) cout << " ";
        for( ; j < N+i; j++) cout << "*";
        cout << '\n';
    }
}