#include <iostream>
#include <string.h>

using namespace std;

int lastWordLength(char *str) {
    if (NULL == str || 0 == strlen(str)) {
        return 0;
    }
    int len = strlen(str);
    bool word_flag = false;
    int last_word_len = 0;
    for (int i = len - 1; i >= 0; --i) {
        if (!word_flag) {
            if (str[i] == ' ') {
                continue;
            } else {
                ++last_word_len;
                word_flag = true;
            }
        } else {
            if (str[i] == ' ') {
                break;
            }
            else {
                ++last_word_len;
            }
        }
    }
    return last_word_len;
}

void test() {
    char *str1 = "hello world";
    if (5 == lastWordLength(str1))
        cout<<"success"<<endl;
    else
        cout<<"fail:"<<lastWordLength(str1)<<endl;
    
    char *str2 = "world";
    if (5 == lastWordLength(str2))
        cout<<"success"<<endl;
    else
        cout<<"fail:"<<lastWordLength(str2)<<endl;
    
    char *str3 = "hello world  ";
    if (5 == lastWordLength(str3))
        cout<<"success"<<endl;
    else
        cout<<"fail:"<<lastWordLength(str3)<<endl;
    
    char *str4 = "  hello  world  ";
    if (5 == lastWordLength(str4))
        cout<<"success"<<endl;
    else
        cout<<"fail:"<<lastWordLength(str4)<<endl;
    
    int len;
    char *str5 = "   ";
    len = lastWordLength(str5);
    if (0 == len) {cout<<"success"<<endl;}
    else {cout<<"fail:"<<len<<endl;}
    
    char *str6 = "world   ";
    len = lastWordLength(str6);
    if (5 == len) {cout<<"success"<<endl;}
    else {cout<<"fail:"<<len<<endl;}
    
    char *str7 = "";
    len = lastWordLength(str7);
    if (0 == len) {cout<<"success"<<endl;}
    else {cout<<"fail:"<<len<<endl;}
}

int main() {
    
    test();
    return 0;
}

