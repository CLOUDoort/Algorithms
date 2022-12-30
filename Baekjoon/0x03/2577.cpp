#include <bits/stdc++.h>
using namespace std;

int cnt[10];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int value = a*b*c;
    int length= 0;
    while(value) {
        if(value /= 10 > 0) value /= 10;
        length++;
    }
    value = a*b*c;
    int arr[length+1];
    for(int i = 0; i < length; i++) {
        arr[i]= value % 10;
        value /= 10;
        cnt[arr[i]]++;
    }
    for(int i = 0; i < 10; i++) cout << cnt[i] << '\n';
    return 0;
}