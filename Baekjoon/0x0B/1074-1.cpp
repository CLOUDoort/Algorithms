/*
- 아이디어
    - 1번 사각형일 때 return func1(n-1, r, c);
    - 2번 사각형일 때 return half*half + func1(n-1, r, c-half)
    - 3번 사각형일 때 return 2*half*half + func1(n-1, r-half, c)
    - 4번 사각형일 때 return 3*half*half + func1(n-1, r-half, c-half)
*/

#include <bits/stdc++.h>
using namespace std;

int Z_Search(int n, int r, int c) {
    if(n == 0) return 0;
    int half = 1<<(n-1);
    if(r < half && c < half) return Z_Search(n-1, r, c);
    else if(r < half && c >= half) return half*half + Z_Search(n-1, r, c-half);
    else if(r >= half && c < half) return 2*half*half + Z_Search(n-1, r-half, c);
    else return 3*half*half + Z_Search(n-1, r-half, c-half);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;
    cout << Z_Search(n, r, c);
}