#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> ans;
int N;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for(int i = N-1; i > 0; i--) {
        int tmp = v[i];
        for(int j = i-1; j >= 0; j--) {
            if(tmp < v[j]) {
                ans.insert(ans.begin(), j+1);
                break;
            }
            if(!j) ans.insert(ans.begin(), j);
        }
    }
    ans.insert(ans.begin(), 0);
    for(int a : ans) cout << a << ' ';
}
