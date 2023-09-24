#include <bits/stdc++.h>
using namespace std;

int n;
int a[10002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);

  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      auto ub = upper_bound(a + j + 1, a + n, -a[i] - a[j]);
      auto lb = lower_bound(a + j + 1, a + n, -a[i] - a[j]);
      ans += ub - lb;
    }
  }
  cout << ans;
}