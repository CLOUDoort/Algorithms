#include <bits/stdc++.h>
using namespace std;

int N, L;
deque<int> d;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L;
    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        d.push_back(a);
    }
    int i = 0;
    while(i < L) {
        cout << d[0] << ' ';
        i++;
    }
    d.pop_front();
    for(i = 0; i < N-L; i++) {
        int min = d[0];
        for(int j = 1; j < L; j++){
            if(d[j] < min) min = d[j];
        }
        cout << min << ' ';
        d.pop_front();
    }
}