#include <bits/stdc++.h>
using namespace std;

int main(void) {
    list<int> L = {1, 2};
    // list<int>::iterator t = L.begin();
    auto t = L.begin();
    L.push_front(10); // 10, 1, 2
    cout << *t << '\n';
    L.push_back(5); // 10, 1, 2, 5
    L.insert(t, 6);
    t++;
    t = L.erase(t);
    cout << *t << '\n';
    for(auto i : L) cout << i << ' ';
    cout << '\n';
    for(list<int>::iterator it = L.begin(); it != L.end(); it++) cout << *it << ' ';
}