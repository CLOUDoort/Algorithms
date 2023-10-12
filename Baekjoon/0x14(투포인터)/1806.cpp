#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, s; cin >> n >> s;
  for(int i = 0; i < n; i++) cin >> a[i];
  int mn = 0x7fffffff;
  int tot = a[0], en = 0;
  for(int i = 0; i < n; i++) {
    while(en < n && tot < s) {
      en++;
      if(en != n) tot += a[en];
    }
    if(en == n) break;
    tot -= a[i];
    mn = min(mn, en-i+1);
  }
  if(mn == 0x7fffffff) mn = 0;
  cout << mn;
}