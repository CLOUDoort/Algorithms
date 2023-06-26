#include <bits/stdc++.h>
using namespace std;

int n, st, total;
int arr[12], operate[12];

void calculate() {
    for(int i = 1; i < n; i++) {
        // 덧셈
        if(operate[i-1] == 0) {
            total += arr[i];
        }
        // 뺄셈
        else if(operate[i-1] == 1) {
            total -= arr[i];
        }
        // 곱셉
        else if(operate[i-1] == 2) {
            total *= arr[i];
        }
        // 나눗셈
        else {
            total /= arr[i];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < 4; i++) {
        int a, j; cin >> a;
        for(j = st; j < st+a; j++) {
            operate[j] = i;
        }
        st = j;
    }
    int mx = INT_MIN, mn = INT_MAX;
    do {
        total = arr[0];
        calculate();
        mx = max(mx, total);
        mn = min(mn, total);
    } while(next_permutation(operate, operate+n-1));
    cout << mx << '\n' << mn;
}