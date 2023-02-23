/*
- 아이디어 O(N^2)
    - 사이클에 포함된 학생을 제외한 학생들이 팀을 만들지 못한 학생들
    - 자기 자신부터 시작해서 계속 사이클을 형성해나가는데 끝까지 자기 자신을 만나지 못한 학생은 팀 결성 못함
    - n명의 학생들마다 각각 n번 이내에 자기 자신으로 돌아오는지 여부를 통해 사이클 포함 여부를 확인한다.
- 이 풀이의 문제점
    - 이미 체크한 학생을 중복 체크해서 시간 내에 해결하지 못한다.
    - 방문 체크를 통해 중복을 제거해야 한다
    => BFS 이용 
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];

bool iscycle(int idx) {
    int cur = idx;
    for(int i = 0; i < n; i++) {
        cur = arr[cur];
        if(cur == idx) return true;
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> arr[i];
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            // 끝까지 자기 자신 만나지 못한 사람 => 사이클 형성 못한 사람
            if(!iscycle(i)) ans++;
        }
        cout << ans << '\n';
    }    
}