/*
비어있는 리스트에서 시작해 수를 하나씩 추가하면서 길이가 M인 수열이 완성되면 출력하는 방식으로 구현
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
bool isUsed[10];

void func(int k) {
    if(k == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++) {
        if(!isUsed[i]) {
            arr[k] = i;
            isUsed[i] = 1;
            func(k+1);
            isUsed[i] = 0;
            // arr는 0으로 변경할 필요없다. 어차피 다른 값으로 덮이기 떄문
        }
    }

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    func(0);
}