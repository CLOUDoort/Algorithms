#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, sum = 0;
    int N;
    cin >> N; 
    for(i = 3; i < N; i++) {
        if(i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    cout << sum;
    return 0;
}