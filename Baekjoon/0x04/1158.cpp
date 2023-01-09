#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> V, ans;

    for(int i = 1; i <= N; i++) V.push_back(i);

    for(int i = 0; ans.size() < N; i++) { // 정답 벡터에 n개의 원소가 쌓이면 종료
        if(i % K == K-1) ans.push_back(V[i]);  // K번째 사람일 때
        else V.push_back(V[i]);
    }
    cout << "<";
    for(int i = 0; i < N; i++) {
        if(i == N-1) cout << ans[i];
        else cout << ans[i] << ", ";
    }
    cout << ">";
}