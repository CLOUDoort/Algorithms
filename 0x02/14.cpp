#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long A, B;
    while(1) {
     cin >> A >> B;
     if(A >= 1 && B >= 1 && A <= 10e15 && B <= 10e15) {
        if(B > A){
            if(B - A <= 100000) break;
        }  
        else if(A > B) {
            if(A - B <= 100000) break;
        }
        else break;
      }
     }

    if(B > A) {
        cout << B-A-1 << '\n';
        for(long long i = A+1; i < B; i++) {
            cout << i << " ";
        }
    } else if(A > B) {
        cout << A-B-1 << '\n';
        for(long long i = B+1; i < A; i++) {
          cout << i << " ";
        }
    } else {
        cout <<  0;
    }
}