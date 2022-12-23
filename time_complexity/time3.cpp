#include <bits/stdc++.h>
using namespace std;

int func3(int N);

int main()
{
    int N;
    cin >> N;
    cout << func3(N);

    return 0;
}

int func3(int N) {
    int i, cnt = 0;
    for(i = 1; i*i <= N; i++) {
        if(i*i == N) return 1;
    }
    return 0;
}

// O(√N)