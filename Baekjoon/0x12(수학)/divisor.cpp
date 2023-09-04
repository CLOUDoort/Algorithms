#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> divisor(int n) {
    vector<int> div;
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) div.push_back(i);
    }
    // vector size 함수는 unsigned int를 반환한기 때문에 조심해야 함
    for(int j = (int)div.size()-1; j >= 0; j--) {
        if(div[j]*div[j] == n) continue;
        div.push_back(n/div[j]);
    }
    return div;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;  
    vector<int> div = divisor(n);
    for(int a : div) cout << a << '\n';   
}