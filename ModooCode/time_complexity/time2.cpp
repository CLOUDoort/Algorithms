#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int N);

int main()
{
    int N, i;
    cin >> N;
    int arr[1000];
    for(i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << func2(arr, N);
    return 0;

}

int func2(int arr[], int N)
{
    int i, j;

    for(i = 0; i < N; i++) {
        for(j = i+1; j < N; j++) {
            if(arr[i] + arr[j] == 100) return 1;
        }
    }
    return 0;
}