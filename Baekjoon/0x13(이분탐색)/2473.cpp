#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sol[5000];
ll ans[3] = {0x7f7f7f7f7f7f, 0x7f7f7f7f7f7f, 0x7f7f7f7f7f7f};
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for(int i = 0; i < N; i++)
    cin >> sol[i];
  sort(sol, sol+N);

  // 두 용액을 섞은 결과에 하나의 용액을 더 섞어서 0으로 만드는 가장 가까운 용액 찾기
  for(int i = 0; i < N; i++){
    for(int j = i+1; j < N; j++){
      int idx = lower_bound(sol, sol+N, -sol[i] - sol[j]) - sol;

      // idx-2, idx-1, idx, idx+1, idx+2 위치에 있는 용액이 최적일 수 있다.
      for(int k = -2; k <= 2; k++){
        if(idx+k == i || idx+k == j) continue;
        if(idx+k < 0 || idx+k >= N) continue;
        if(abs(ans[0] + ans[1] + ans[2]) > abs(sol[i] + sol[j] + sol[idx+k]))
          tie(ans[0], ans[1], ans[2]) = {sol[i], sol[j], sol[idx+k]}; // tie를 이용해 값 3개를 한번에 assign.        
      }
    }
  }
  sort(ans, ans+3); // 출력 형식 맞추기.
  cout << ans[0] << " " << ans[1] << " " << ans[2];
}