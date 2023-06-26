#include <bits/stdc++.h>
#define MX 5000010
using namespace std;

int N, L;
int arr[MX];

void input() {
    cin >> N >> L;
    for(int i = 1; i <= N; i++) cin >> arr[i];
}

void solution() {
    deque<pair<int, int>> d;
    for(int i = 1; i <= N; i++) {
        if(!d.empty()){
            if(d.front().second < i - L + 1) d.pop_front();
        }
        while(!d.empty() && d.back().first > arr[i]) d.pop_back();
        d.push_back(make_pair(arr[i], i));
        cout << d.front().first << " ";
    }
}

void solve()
{
    input();
    solution();
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}