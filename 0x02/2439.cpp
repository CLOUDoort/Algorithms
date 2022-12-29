#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    // for(int i = 0; i < N; i++) {
    //     for(int j = N-1-i; j > 0; j--) cout << " ";
    //     for(int k = 0; k <= i; k++) cout << "*";
    //     cout << '\n';
    // }
    for(int i = 0; i < N; i++) {
        int j = 0;
        for( ; j < N - i - 1; j++) cout << " ";
        for( ; j < N; j++) cout << "*";
        cout << '\n';
    }
}