// 주어진 길이 N의 배열 arr에서 합이 100인 서로 다른 위치의 두 원소가 존재하면 1을, 존재하지 않으면 0을 반환하는 함수 func2(int arr[], int N)을 작성하라.
// arr의 각 수는 0 이상 100이하이고 N은 1000 이하이다.

#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int N) {
    int occur[101] = {};
    for(int i = 0; i < N; i++) {
        if(occur[100-arr[i]]) return 1;
        // 배열에서 원소를 찾는 것은 O(1) 
        // 즉 이 구현의 시간복잡도는 O(N)이다.
        occur[arr[i]] = 1;
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, arr[1001];
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    cout << func2(arr, N);
    return 0;
}