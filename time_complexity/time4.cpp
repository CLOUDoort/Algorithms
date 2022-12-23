#include <bits/stdc++.h>
using namespace std;

int func4(int N);

int main()
{
    int N;
    cin >> N;
    cout << func4(N);
    return 0;
}

int func4(int N){
    int val = 1;
    while(2*val <= N) val *= 2;
    return val;
}

// O(lgN);

// int func4(int N) {
//     int max;
//     for(int i = 1; pow(2, i) <= N; i++) {
//         max = pow(2, i);
//     }
//     return max;
// }