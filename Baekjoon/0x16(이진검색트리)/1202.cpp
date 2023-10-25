// 가장 가격이 높은 보석부터 확인하며 해당 보석을 담을 수 있는 가방 중 최대 무게가 가장 작은 가방 선택
#include <bits/stdc++.h>
using namespace std;

// 무게, 가격
pair<int, int> jw[300001];

// 가방 무게
multiset<int> bag;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> jw[i].second >> jw[i].first;
  }
  sort(jw, jw+n);
  while(k--) {
    int a; cin >> a;
    bag.insert(a);
  }
  long long ans = 0;
  for(int i = n-1; i >= 0; i--) {
    int m, v;
    tie(v, m) = jw[i];
    auto it = bag.lower_bound(m);
    if(it == bag.end()) continue;
    ans += v;
    bag.erase(it);
  }
  cout << ans;
}
