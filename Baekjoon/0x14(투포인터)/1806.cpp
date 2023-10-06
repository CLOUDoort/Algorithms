#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, s; cin >> n >> s;
  for(int i = 0; i < n; i++) cin >> a[i];
  int mn = 0x7fffffff;
  int en = 0;
  int tot = a[0];
  for(int st = 0; st < n; st++) {
    while(en < n && tot < s) {
      en++;
      if(en != n) tot += a[en];
    }
    if(en == n) break;
    mn = min(mn, en-st+1);
    tot -= a[st];
  }
  if(mn == 0x7fffffff) mn = 0;
  cout << mn;  
}