/*
    최소개수의 꽃을 선택 => 겹치는 날이 최소로 적어야 한다.
    즉 3월 1일부터 11월 30일까지 개화하는 꽃이 겹치는 개수가 최소로 적어야 한다.
    꽃이 지는 날이 최소 3월 2일이면서 가장 오래 피는 꽃을 시작으로
    마지막 꽃이 지는 날이 최소 12월 1일인 꽃으로 마무리
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int, int>> flower;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    pair<int, int> cur = {0, 0};
    for(int i = 0; i < n; i++) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        flower.push_back({sm*100+sd, em*100+ed});
    }
    int t = 301, ans = 0;
    while(t < 1201) {
        int nxt_t = t;
        for(int i = 0; i < n; i++) {
            if(flower[i].X <= t && flower[i].Y > nxt_t) {
                nxt_t = flower[i].Y;
            }
        }
        if(nxt_t == t) {
            cout << 0; return 0;
        }
        ans++; 
        t = nxt_t;
    }
    cout << ans;
}