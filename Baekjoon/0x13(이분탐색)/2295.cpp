/*
    a[i]+a[j]+a[k] = a[l]을 만족하는 a[l]중에서 최댓값
    two 배열을 만들어서 2개의 수를 합한 값을 저장한다.
    two[m] + a[k] = a[l]을 만족하는 a[l]중에서 최댓값

    2개를 묶거나 한 후 어느 한 쪽의 값을 이분탐색으로 찾아서 시간복잡도를 낮추는 아이디어
    이분탐색 응용 문제에서 핵심적으로 많이 나옴
*/

#include <bits/stdc++.h>
using namespace std;

int a[1002];
vector<int> two;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            two.push_back(a[i]+a[j]);
        }
    }
    sort(two.begin(), two.end());
    for(int i = n-1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(binary_search(two.begin(), two.end(), a[i]-a[j])) {
                cout << a[i];
                return 0;
            }
        }
    }
}