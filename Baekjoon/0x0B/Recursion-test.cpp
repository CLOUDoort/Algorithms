#include <bits/stdc++.h>
using namespace std;

int add(int n) {
    if(n == 0) return 0;
    return n+add(n-1);
}
void func2(int n) {
    if(n == 0) return;
    cout << n << ' ';
    func2(n-1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    printf("\n");
    printf("1부터 100까지의 합: %d\n", add(1000000));
}