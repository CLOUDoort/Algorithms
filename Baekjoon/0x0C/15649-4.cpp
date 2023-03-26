#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10], isUsed[10];

void func(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!isUsed[i]) {
            arr[cnt] = i;
            isUsed[i] = 1;
            func(cnt+1);
            isUsed[i] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}