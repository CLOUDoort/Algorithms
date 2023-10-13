#include <bits/stdc++.h>
using namespace std;

const int MAN = 4000002;

vector<bool> state(MAN, true);
vector<int> primes;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  state[1] = false;
  for(int i = 2; i*i < MAN; i++) {
    if(!state[i]) continue;
    for(int j = i*i; j < MAN; j += i) {
      state[j] = false;
    }
  }
  for(int i = 2; i < MAN; i++) {
    if(state[i]) primes.push_back(i);
  }
  primes.push_back(0);
  int target, s = 0, e = 1, ans = 0, tmpSum = primes[0];
  cin >> target;
  while(1) {
    if(tmpSum == target) ans++;
    if(tmpSum <= target) tmpSum += primes[e++];
    if(target < tmpSum) tmpSum -= primes[s++];
    if(e == int(primes.size())) break;
  }
  cout << ans;
}