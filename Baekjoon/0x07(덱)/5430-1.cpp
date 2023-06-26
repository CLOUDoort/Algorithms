#include <bits/stdc++.h>
using namespace std;

void parse(string& tmp, deque<int>& d){
    int cur = 0;
    for(int i = 1; i+1<tmp.size(); i++){
        if(tmp[i] == ','){
            d.push_back(cur);
            cur = 0;
        }
        else {
            // string => int
            cur = 10 * cur + (tmp[i] - '0');
        }
    }
    if(cur != 0) {
        d.push_back(cur);
    }
}
void print_result(deque<int>& d){
    cout << '[';
    for(int i = 0; i < d.size(); i++){
        cout << d[i];
        if(i+1 != d.size()) cout << ',';
    }
    cout << "]\n";
}

int t;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        deque<int> d;
        int rev = 0;
        bool isWrong = false;
        int n;
        string query, tmp;
        cin >> query; // 명령어
        cin >> n; // 배열 원소 개수
        cin >> tmp; // 배열 입력
        parse(tmp, d);
        for(char c : query)
        {
            if(c == 'R') rev = 1 - rev;
            else {
                if(d.empty()){
                    isWrong = true;
                    break;
                }
                if(!rev) d.pop_front();
                else d.pop_back();
            }
        }
        if(isWrong) cout << "error\n";
        else{
            if(rev) reverse(d.begin(), d.end());
            print_result(d);
        }
    }
}