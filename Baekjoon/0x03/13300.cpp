#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K, s, t, t_length[10] = {}, s_sum[10] = {}, value = 0;
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> s >> t;
        switch(t) {
            case 1:
                t_length[1]++;
                s_sum[1] += s;
                break;
            case 2:
                t_length[2]++;
                s_sum[2] += s;
                break;
            case 3:
                t_length[3]++;
                s_sum[3] += s;
                break;
            case 4:
                t_length[4]++;
                s_sum[4] += s;
                break;
            case 5:
                t_length[5]++;
                s_sum[5] += s;
                break;
            case 6:
                t_length[6]++;
                s_sum[6] += s;
                break;
        }
    }

    for(int i = 1; i <= 6; i++) {
        if(t_length[i]) {
            int M = s_sum[i];
            int F = t_length[i] - s_sum[i];
            value = value + (M+(K-1))/K + (F+(K-1))/K;
        }
    }
    cout << value;
}