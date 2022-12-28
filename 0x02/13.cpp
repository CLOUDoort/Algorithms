#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a[9], result[7], sum = 0, value = 0, n = 0;
    int delete_num[2];
    for(int i = 0; i < 9; i++) {
        cin >> a[i];
        sum += a[i];
    }
    value = sum - 100;
    for(int i = 0; i < 9; i++) {
        for(int j = i+1; j < 9; j++) {
            if(a[i] + a[j] == value) {
                delete_num[0] = a[i];
                delete_num[1] = a[j];
                break;
            }
        }
    }
    for(int i = 0; i < 9; i++) {
        if(a[i] == delete_num[0] || a[i] == delete_num[1]) continue;
        result[n] = a[i];
        n++;
    }
    sort(result, result+7);
    for(int i = 0; i < 7; i++) {
        cout << result[i] << '\n';
    }
}