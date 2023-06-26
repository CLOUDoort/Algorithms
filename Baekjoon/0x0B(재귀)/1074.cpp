/*
- 아이디어
    - 아이디어
    - base condition 설정, 웬만하면 0으로 설정하는 것이 편하다.

    - n이 1일 때는 0을 리턴하는데, 열 값이 half보다 크면 1, 행 값이 half보다 크면 2, 행과 열이 half보다 크면 3을 더함으로써 최소 좌표의 값을 알 수 있게 된다. 
    <hr />
    정리하면
    - 1분면의 좌표의 값을 구하려면 다른 값을 더할 필요 없이 n-1한 값을 재귀 돌린다.
    - 2분면의 좌표의 값을 구하려면 1분면의 크기만큼 더하고 n-1 값과 열에서 half만큼 뺀 값으로 재귀 돌린다.
    - 3분면의 좌표의 값을 구하려면 1, 2분면의 크키만큼 더하고 n-1값과 행에서 half만큼 뺀 값으로 재귀 돌린다.
    - 4분면의 좌표의 값을 구하려면 1, 2, 3분면의 크기만큼 더하고 n-1값과 행, 열에서 half만큼 뺀 값으로 재귀 돌린다.

    - half 값은 1에서 n-1값을 left shift한 값을 사용하면 된다.
*/

#include <bits/stdc++.h>
using namespace std;

int n, r, c;

int func(int n, int r, int c) {
    // base condition
    if(n == 0) return 0;
    int half = 1<<(n-1);
    if(r < half && c < half) return func(n-1, r, c);
    if(r < half && c >= half) return half*half + func(n-1, r, c-half);
    if(r >= half && c < half) return 2*half*half + func(n-1, r-half, c);
    return 3*half*half + func(n-1, r-half, c-half);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r >> c;
    cout << func(n, r, c);
}