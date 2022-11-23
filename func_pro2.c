#include <stdio.h>

int gcd(int a, int b);

int main()
{
    int N, i;
    int arr[100];
    int gcd_arr[100];
    while(1) {
        scanf("%d", &N);
        if(N >= 2) break;
    }

    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    gcd_arr[0] = gcd(arr[0], arr[1]);
    for(i = 1; i < N-1; i++) {
        gcd_arr[i] = gcd(gcd_arr[i-1], arr[i+1]);
    }

    printf("최대공약수 : %d \n", gcd_arr[N-2]);
    return 0;

}

int gcd(int a, int b)
{
    int r = a % b;
    if(r == 0) return b;
    return gcd(b, r);
}