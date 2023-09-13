#include <bits/stdc++.h>
using namespace std;

int e, s, m;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a/gcd(a, b)*b;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> e >> s >> m;
  e--, s--, m--;

  int i = e;
  while(i % 28 != s) i += 15;

  int l = lcm(15, 28);
  while(i % 19 != m) i += l;
  cout << i + 1;
}