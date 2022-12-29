#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, input, sumA = 0, sumB = 0;
    while(1) {
        cin >> N;
        if(N <= 20) break;
    }
    for(int i = 0; i < N; i++) {
        cin >> input;
        sumA += (input/30 +1) * 10;
        sumB += (input/60 + 1) * 15;
    }
    if(sumA > sumB) cout << "M " << sumB;
    else if(sumA < sumB) cout << "Y " << sumA;
    else cout << "Y M " << sumA;
}