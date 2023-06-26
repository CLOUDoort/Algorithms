#include <bits/stdc++.h>
using namespace std;

int main(void){
    deque<int> DQ;
    DQ.push_front(10);
    DQ.push_back(50);
    DQ.push_front(24);
    for(auto x : DQ) cout << x;
    cout << DQ.size() << '\n';
    if(DQ.empty()) cout << "DQ is empty \n";
    else cout << "DQ is not empty \n";
    DQ.pop_front();
    DQ.pop_back();
    cout << DQ.back();
    DQ.push_back(72);
    cout << DQ.front();
    DQ.push_back(12);
    DQ[2] = 17;
    DQ.insert(DQ.begin()+1, 33);
    DQ.insert(DQ.begin()+4, 60);
    for(auto x : DQ) cout << x << ' ';
    cout << '\n';
    DQ.erase(DQ.begin()+3);
    cout << DQ[3] << '\n';
    DQ.clear();

}