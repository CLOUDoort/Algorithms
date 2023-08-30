#include <bits/stdc++.h>
using namespace std;

// m은 작은 수부터, p는 큰 수부터
int m[52], p[52], ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int midx = 0, pidx = 0, zidx = 0;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(a < 0) m[midx++] = a;
        else if(a > 0) p[pidx++] = a;
        else zidx++;
    }
    sort(m, m+midx); sort(p, p+pidx);
    for(int i = 0; i < midx-1; i += 2) {
        ans += (m[i]*m[i+1]);
    }
    // 0의 유무 확인 필요
    if(!zidx && midx % 2 != 0) ans += m[midx-1];
    for(int i = pidx-1; i >= 1; i -= 2) {
        // 1일 때는 곱하는 것보다 더하는 값이 더 큼
        if(p[i-1] == 1) ans += (p[i]+p[i-1]);
        else ans += (p[i]*p[i-1]);
    }
    // 0은 따로 예외처리 해줘야 함, 아니면 p[0]*p[-1]이라는 결과 도출
    if(pidx % 2 != 0) ans += p[0];
    cout << ans;
}