// 주어진 길이 N의 배열 arr에서 합이 100인 서로 다른 위치의 두 원소가 존재하면 1을, 존재하지 않으면 0을 반환하는 함수 func2(int arr[], int N)을 작성하라.
// arr의 각 수는 0 이상 100이하이고 N은 1000 이하이다.

#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int N){
    for(int i = 0; i < N; i++) {
        int cmp = 100 - arr[i];
        for(int j = 0; j < i; j++) {
            if(arr[j] == cmp) return 1;
        }
    }
    return 0;
}

int main(void) {
    int N;
    cin >> N;
    int arr[100];
    for(int i = 0; i < N; i++) cin >> arr[i];
    cout << func2(arr, N);
    return 0;    
}