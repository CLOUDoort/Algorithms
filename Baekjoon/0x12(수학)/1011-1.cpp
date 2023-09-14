#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        ll x, y;
        cin >> x >> y;
		ll dist = y-x; // 두 지점 사이의 거리
		double dpow = sqrt(dist); // 거리의 제곱근
		int pow = round(sqrt(dist)); // 거리의 제곱근을 반올림
		
		if(dpow <= pow) cout << pow * 2 - 1 << "\n"; 
		else cout << pow * 2 << "\n"; 
    }
}