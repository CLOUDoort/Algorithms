#include <bits/stdc++.h>
using namespace std;


// d[i]  = i-1번째 날까지 상담을 했을 때 벌 수 있는 최대 금액
int d[20], t[20], p[20];
int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> t[i] >> p[i];
    for(int i = 1; i <= n; i++) {
        d[i] = max(d[i], d[i-1]);
        if(i+t[i]-1 <= n) {
            d[i+t[i]] = max(d[i+t[i]], d[i]+p[i]);
        }
    }
    cout << max(d[n], d[n+1]);
}