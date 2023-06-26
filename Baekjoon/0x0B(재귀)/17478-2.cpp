#include <bits/stdc++.h>
using namespace std;

int n;

void PrintUnderbar(const char* a, int N) {
    for(int i = N; i < n; i++) cout << "____";
    cout << a;
}

void Func1(int N) {
    PrintUnderbar("\"재귀함수가 뭔가요?\"\n", N);
    if(N == 0) {
        PrintUnderbar("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n", N);
    }
    else {
        PrintUnderbar("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n", N);
        PrintUnderbar("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n", N);
        PrintUnderbar("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n", N);
        Func1(N-1);
    }
    PrintUnderbar("라고 답변하였지.\n", N);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    Func1(n);
}