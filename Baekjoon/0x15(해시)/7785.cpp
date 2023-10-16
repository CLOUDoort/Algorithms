#include <bits/stdc++.h>
using namespace std;

vector<string> enter, leave;
bool comp(string a, string b) {
    return a > b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string name, log; cin >> name >> log;
        if(log == "enter") enter.push_back(name);
        else leave.push_back(name);
    }
    sort(enter.begin(), enter.end(), comp);
    sort(leave.begin(), leave.end(), comp);
    for(int i = 0; i < (int)enter.size(); i++) {
        if(!binary_search(leave.begin(), leave.end(), enter[i])) {
            cout << enter[i] << '\n';
        }
    }
}