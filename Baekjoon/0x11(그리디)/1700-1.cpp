#include <bits/stdc++.h>
using namespace std;

int a[103], ans, cnt;
bool power[103];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    for(int i = 1; i <= k; i++) cin >> a[i];
    for(int i = 1; i <= k; i++) {
        int cur = a[i];
        // power true면 continue
        if(power[cur]) continue;
        // plug에 없는데 plug 자리가 있으면 넣기
        if(cnt < n) {
            power[cur] = true;
            cnt++;
        }
        // power도 off고 plug도 자리가 없을 때, 대체자리 찾기
        // plug에 꽂힌 전자기기 중에서 가장 늦게 사용할 전자기기 선택해서 뽑기
        else {
            vector<pair<int, int>> v;
            for(int x = 1; x <= k; x++) {
                if(!power[x]) continue;
                bool vis = false;
                for(int y = i+1; y <= k; y++) {
                    if(a[y] == x) {
                        v.push_back({y, x});
                        vis = true;
                        break;
                    }
                }
                if(!vis) v.push_back({k+1, x});
            }
            sort(v.begin(), v.end(), greater<pair<int, int>>());
            power[cur] = true;
            power[v[0].second] = false;
            ans++;
        }
    }
    cout << ans;
}