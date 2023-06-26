#include <bits/stdc++.h>
using namespace std;

void sortArr(int *arr, int a, int b) {
    for(int i = 0; i < (b-a+1)/2; i++) {
        swap(*(arr+a-1+i), *(arr+b-1-i));
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[20];
    int cnt = 1;
    for(int i = 0; i < 20; i++) arr[i] = cnt++;
    int a, b;
    for(int i = 0; i < 10; i++) {
        cin >> a >> b;
        if(a > b) swap(a, b);
        sortArr(arr, a, b);
    }
    for(int i = 0; i < 20; i++) cout << arr[i] << ' ';
}