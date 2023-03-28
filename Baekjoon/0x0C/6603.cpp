/*
- 아이디어
    - k개 중에서 6개를 뽑는 조합 구하기
    - 각 테스트 케이스가 존재, 0이 나오면 종료
    - 중복 숫자 없으니 temp 사용 안해도됨
    - isUsed대신 cur 변수를 통해 조합 출력
*/
#include <bits/stdc++.h>
using namespace std;

int k, input[20], arr[10];

void func(int cnt, int cur) {
    if(cnt == 6) {
        for(int i = 0; i < 6; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = cur; i < k; i++) {
        arr[cnt] = input[i];
        func(cnt+1, i+1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        cin >> k;
        if(k == 0) break;
        for(int i = 0; i < k; i++) cin >> input[i];
        func(0, 0);
        cout << '\n';
    }
}
