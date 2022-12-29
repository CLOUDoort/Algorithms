#include <string.h>
#include <iostream>

class string {
    char *str;
    int len;

    public:
        string(char c, int n);
        string(const char* s);
        string(const string &s);
        ~string();

        void add_string(const string &s);
        void copy_string(const string &s);
        void print_string();
        int strlen();
};

string::string(char c, int n) {
    str = new char[n+1];
    for(int i = 0; i < n; i++) str[i] = c;
    str[n] = '\0';
    len = n;
}
string::string(const char* s) {
    for(len = 0; s[len] != '\0'; len++);
    str = new char[len+1];
    for(int i = 0; i < len; i++) str[i] = s[i];
}
string::string(const string &s) {
    str = new char[s.len+1];
    for(int i = 0; i <= s.len+1; i++) str[i] = s.str[i];
    len = s.len;
}
void string::add_string(const string &s) {
    char *new_str = new char[len + s.len+1];
    for(int i = 0; i < len; i++) new_str[i] = str[i];
    for(int i = len; i < len+s.len+1; i++) new_str[i] = s.str[i-len];
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
void string::print_string() {
    std::cout << str << std::endl;
}
int string::strlen() { return len; }
string::~string() { delete[] str; }

int main() {
    string s1('a', 10);
    string s2("goddamn");
    string s3(s2);
    std::cout << s1.strlen() << std::endl << s2.strlen() << std::endl << s3.strlen() << std::endl;
    s1.print_string();
    s2.print_string();
    s3.print_string();

    s1.add_string(s2);
    s3.copy_string(s1);
    std::cout << s1.strlen() << std::endl << s2.strlen() << std::endl << s3.strlen() << std::endl;
    s1.print_string();
    s2.print_string();
    s3.print_string();
    return 0;

}