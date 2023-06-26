#include <bits/stdc++.h>
using namespace std;

void HanoiTower(int a, int b, int n) {
    if(n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }
    HanoiTower(a, 6-a-b, n-1);
    cout << a << ' ' << b << '\n';
    HanoiTower(6-a-b, b, n-1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << (1<<n)-1 << '\n';
    HanoiTower(1, 3, n);
}