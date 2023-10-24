#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while(t--) {
    int k; cin >> k;
    multiset<int> ms;
    while(k--) {
      char command;
      cin >> command;
      if(command == 'I'){
        int q; cin >> q;
        ms.insert(q);
      } 
      else if(command == 'D') {
        int q; cin >> q;
        if(ms.empty()) continue;
        if(q == -1) ms.erase(ms.begin());
        else ms.erase(prev(ms.end()));
      }
    }
    if(ms.empty()) cout << "EMPTY\n";
    else cout << *prev(ms.end()) << ' ' << *ms.begin()<< '\n';
  }
}