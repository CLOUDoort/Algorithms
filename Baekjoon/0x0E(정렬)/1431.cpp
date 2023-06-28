#include <bits/stdc++.h>
using namespace std;

int n;
string arr[52];
bool cmp(const string& a, const string& b) {
    if(a.length() != b.length()) return a.length() < b.length(); 
    int a_sum = 0, b_sum = 0;
    for(int i = 0; i < a.length(); i++) {
        if(isdigit(a[i])) a_sum += a[i] -'0';
        if(isdigit(b[i])) b_sum += b[i] -'0';
    }
    if(a_sum != b_sum) return a_sum < b_sum;
    return a < b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n, cmp);

    for(int i = 0; i < n; i++) cout << arr[i] << '\n';
}