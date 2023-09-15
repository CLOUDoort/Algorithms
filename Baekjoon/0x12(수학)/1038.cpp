// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/2300d12c7a24426a97284f983d31b3fa
#include <bits/stdc++.h>
using namespace std;

vector<bool> a(10, 0);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cnt = 0;

  int n; cin >> n;
  for(int i = 1; i <= 10; i++) {
    a[10 - i] = 1;
    do {
      if(cnt != n) {
        cnt++;
        continue;
      }
      for(int i = 0; i < 10; i++)
        if(a[i]) cout << 9 - i;
      return 0;
    } while(next_permutation(a.begin(), a.end()));
  }
  cout << -1;
}