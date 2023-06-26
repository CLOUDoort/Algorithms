#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int arr[1000001];
int unused = 1;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    while(N--) {
        int A;
        cin >> A;
        if(!s.empty()) {
            if(s.top() < A)  {
                if(s.size() == 1) {
                    cout << A << ' ';
                    s.pop();
                }
                else {
                    while(!s.empty()) {
                    if(s.top() < A) {
                        arr[unused] = A;
                        unused++;
                    }
                    else {
                        arr[unused] = -1;
                        unused++;
                    }
                    s.pop();
                }
                }
            }
            else if(s.top() == A) {
                cout << -1 << ' ';
                s.pop();
            }
            else {
                if(N == 0) {
                    while(!s.empty()) {
                        cout << -1 << ' ';
                        s.pop();
                    }
                }
            }
        }
        s.push(A);
    }
    unused--;
    for(int i = unused; i >= 1; i--) {
        cout << arr[i] << ' ';
    }
    cout << -1;
}