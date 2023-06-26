#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int value = a*b*c;
    int cnt[10] ={};
    while(value>0) {
        cnt[value%10]++;
        value /= 10;
    }
    for(int i = 0; i < 10; i++) cout << cnt[i] << '\n';
    return 0;
}