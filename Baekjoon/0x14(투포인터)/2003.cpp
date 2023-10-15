// 연속한 수에서 경우의 수 => 정렬x

#include <bits/stdc++.h>
using namespace std;

int a[10002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> a[i];
  int ans = 0, en = 0, tot = a[0];
  for(int i = 0; i < n; i++) {
    while(en < n && tot < m) {
      en++;
      if(a[en] == m) {
        tot = 0;
        ans++;
        break;
      }
      tot += a[en];
    }
    if(en == n) break;
    if(tot == m) {
      ans++;
      tot -= a[i];
    }
    else if(tot > m) tot -= a[i];
  }
  cout << ans;
}