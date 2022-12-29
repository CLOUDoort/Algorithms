#include <string.h>
#include <iostream>

class string {
    char *str;
    int len;

    public:
        string(char c, int n); // 문자 c가  n개 있는 문자열로 정의
        string(const char* s);
        string(const string &s);
        ~string();

        void add_string(const string &s); // str 뒤에 s를 붙인다.
        void copy_string(const string &s); // str 뒤에 s를 복사한다
        void print_string();
        int strlen(); // 문자열 길이 return
};
string::string(char c, int n) {
    str = new char[n+1];
    for(int i = 0; i < n+1; i++) str[i] = c;
    str[n] = '\0';
    len = n;
}
string::string(const char* s) {
    for(len = 0; s[len] != '\0'; len++);
    str = new char[len+1];
    for(int i = 0; i < len+1; i++) str[i] = s[i];
}
string::string(const string &s) {
    str = new char[s.len+1];
    for(int i = 0; i < s.len+1; i++) str[i] = s.str[i];
    len = s.len;
}
string::~string() { delete[] str; }
void string::add_string(const string &s) {
    char* new_str = new char[len+s.len+1];
    for(int i = 0; i < len; i++) new_str[i] = str[i];
    for(int i = len; i < len+s.len+1; len++) new_str[i] = s.str[i-len];
    delete[] str;
    str = new_str;
    len += s.len;
}
void string::copy_string(const string &s) {
    char* new_str = new char[s.len+1];
    for(int i = 0; i < s.len+1; i++) new_str[i] = s.str[i];
    delete[] str;
    str = new_str;
    len = s.len;
}