#include <bits/stdc++.h>
using namespace std;

int check[300] = {};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, v, t, value = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> t;
        if(t >= -100 && t <= 100) check[t+100]++;
    }
    cin >> v;
    if(v >= -100 && v <= 100) value = check[v+100];
    cout << value; 
}