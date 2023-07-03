#include <bits/stdc++.h>
using namespace std;

long long A[20002], B[20002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> A[i];
        for(int j = 0; j < m; j++) cin >> B[j];
        int cnt = 0;
        sort(A, A+n); sort(B, B+m);
        int st = 0;
        for(int i = m-1; i >= 0; i--) {
            if(A[n-1] > B[i]) {
                st = i;
                break;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= st; j++) {
                if(A[i] > B[j]) cnt++;
            }
        }
        cout << cnt << '\n';
    }
}