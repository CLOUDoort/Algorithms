/*
- 아이디어
    - 주어진 수 A B C 모두 int 값 범위에 해당함
    - A를 B번 곱하는 순간 int 범위 넘어감
    - 귀납법으로 생각
        - 1번 도미노가 쓰러진다.
        - K번 도미노가 쓰러지면 K+1번 도미노도 쓰러진다.

        - 1승을 계산할 수 있다.
        - K승을 계산했으면 2K승과 2K+1승도 O(1)에 계산할 수 있다.

    - 우선 base condition을 잘 잡아준다.
    - K승의 결과를 토대로 2K, 2K+1승의 결과를 계산할 수 있어야 한다. => 귀납적 사고
    - 시간복잡도는 O(log b)
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll POW(ll a, ll b, ll m) {
    if(b == 1) return a % m;
    ll val = POW(a, b/2, m);
    val = val * val % m;
    if(b%2 == 0) return val;
    return val * a % m;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    cout << POW(a,b,c);
}