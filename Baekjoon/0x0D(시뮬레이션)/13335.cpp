#include <bits/stdc++.h>
using namespace std;

int n, w, L, ans;
int bridge[101];
queue<int> truck;

bool isEmpty() {
    for(int i = 0; i < w; i++) {
        if(bridge[i]) return false;
    }
    return true;
}

int calculate() {
    int sum = 0;
    for(int i = 0; i < w; i++) {
        sum += bridge[i];
    }
    return sum;
}

void go() {
    for(int i = w-1; i > 0; i--) {
        bridge[i] = bridge[i-1];
    }
    bridge[0] = 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w >> L;
    while(n--) {
        int i;
        cin >> i;
        truck.push(i);
    }
    do {
        int tmp = calculate();
        if(tmp <= L) {
            tmp -= bridge[w-1];
            go();
            if(!truck.empty() && (tmp+truck.front() <= L)){
                bridge[0] = truck.front(); truck.pop();
            }
        }
        ans++;
    } while(!isEmpty());
    cout << ans;
}