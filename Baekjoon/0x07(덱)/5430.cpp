#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        deque<int> DQ;
        string p, arr; // 명령어
        int arr_size = 0;
        int isWrong = 0;
        cin >> p; // 명령어
        cin >> arr_size; // 배열 수
        cin >> arr; // 받는 배열
        // deque에 배열 입력
        string ans="";
        for(int i = 0; i < arr.length(); i++) {
            if(isdigit(arr[i])) {
                ans += arr[i];
            }
            else {
                if(!ans.empty()) {
                    DQ.push_back(stoi(ans));
                    ans = "";
                }
            }
        }
        // 명령어 분석
        for(auto o : p) {
            if(o == 'D') {
                if(DQ.empty()) {
                    cout << "error\n";
                    isWrong = 1;
                    break;
                }
                else {
                    DQ.pop_front();
                }
            }
            else {
                reverse(DQ.begin(), DQ.end());
            }
        }
        if(isWrong == 0) {
            cout << "[";
            for(int i = 0; i < DQ.size() ; i++) {
                cout << DQ[i];
                if(i != DQ.size()-1) cout << ',';
            }
            cout << "]\n";
        }
    }
}