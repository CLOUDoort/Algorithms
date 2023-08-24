/*
    최소개수의 꽃을 선택 => 겹치는 날이 최소로 적어야 한다.
    즉 3월 1일부터 11월 30일까지 개화하는 꽃이 겹치는 개수가 최소로 적어야 한다.
    꽃이 지는 날이 3월 2일 이하이면서 가장 오래 피는 꽃을 시작으로
    마지막 꽃이 지는 날이 최소 12월 1일인 꽃으로 마무리(12월1일에 지면 11월 30일까지 개화시기)
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int, int>> t;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        // 날짜 단순화 작업
        t.push_back({sm*100+sd, em*100+ed});
    }
    int cur = 301, ans = 0;
    while(cur < 1201) {
        int temp = cur;
        // 현재 저장된 꽃의 지는 날이 지금 확인하는 꽃의 피는날보다 앞에 있어야 중간에 비지 않는다.
        // for문을 돌리면서 temp 값을 계속해서 업데이트 해주기 때문에 
        // t[i].X <= cur 조건을 만족하는 꽃들 중에서 지는 날이 가장 늦는 꽃을 선택할 수 있다.
        for(int i = 0; i < n; i++) {
            if(t[i].X <= cur && t[i].Y > temp) temp = t[i].Y;
        }
        // 조건에 맞는 꽃이 없기 때문에 종료
        if(temp == cur) {
            cout << 0; return 0;
        }
        ans++;
        cur = temp;
    }
    cout << ans;
}