#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x;
  cin >> x;

  // x에서 1 2 3 ...을 빼다보면 찾는 수가 i 번째 군의 x 번째 수가 된다.
  int i = 1;
  while (x > i) {
    x -= i;
    i++;
  }

  int nume = x;
  int deno = i + 1 - x;
  if (i % 2) swap(nume, deno);  // 홀수 번째 군의 순서가 문제와 반대이므로 뒤집는다.
  cout << nume << '/' << deno;
}