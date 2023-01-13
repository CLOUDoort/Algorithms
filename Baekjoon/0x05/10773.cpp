#include <bits/stdc++.h>
using namespace std;

int K, sum = 0;
stack<int> S;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K;

    while(K--) {
        int a;
        cin >> a;
        if(a == 0) S.pop();
        else S.push(a);
    }

    while(!S.empty()) {
        sum += S.top();
        S.pop();
    }

    cout << sum;
    // while(K--){
    //     int a;
    //     cin >> a;
    //     if(a == 0) {
    //         if(!S.empty()) {
    //             sum -= S.top();
    //             S.pop();
    //         }
    //     } else {
    //         S.push(a);
    //         sum += a;
    //     }
    // }
}