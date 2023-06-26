#include <bits/stdc++.h>
using namespace std;

int N, M, sum;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    deque<int> DQ;
    for(int i = 1; i <= N; i++) DQ.push_back(i);
    cin >> M;
    while(M--) {
        int index;
        cin >> index;
        int idx = find(DQ.begin(), DQ.end(), index) - DQ.begin();
        while(DQ.front() != index) {
            if(idx < DQ.size() - idx) {
                DQ.push_back(DQ.front());
                DQ.pop_front();
            }
            else {
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
            sum++;
        }
        DQ.pop_front();
    }
    cout << sum;
}