#include <iostream>
#include <string>
#include "string.h"
#include<vector>

using namespace std;

// next in KMP
// next[j] = m means that 
// needle[0,...,m-1] = needle[j - m + 1,...,j]
// But when traversaling m, it's not needed always to compare from needle[0]
void get_next_simple(char *needle, vector<int> &next) {
    int n = strlen(needle);
    next.push_back(0);
    for(int i = 1; i < n; ++i) {
        int len;
        int max_len = 0;
        for (len = 1; len <= i; ++len) {
            int j;
            for (j = 0; j < len; ++j) {
                if (needle[i - len + 1 + j] != needle[j]) {
                    break;
                }
            }
            if (j < len) {
                continue;
            } else {
                max_len = len;
            }
        }
        next.push_back(max_len);
    }
}

void get_next(char *needle, vector<int> &next) {
    int n = strlen(needle);
    for (int i = 0; i < n; ++i) {
        next.push_back(0);
    }
    int i = 1;
    int j = 0;
    while (i < n) {
        if (needle[i] == needle[j]) {
            next[i] = j + 1;
            i++;
            j++;
        } else if (j > 0) {
            j = next[j - 1];
        } else {
            next[i] = 0;
            i++;
        }
    }
}

// KMP
int strStr(char *haystack, char *needle) {
    int i = 0;
    int j = 0;
    int hlen = strlen(haystack);
    int nlen = strlen(needle);
    vector<int> next;
    get_next(needle, next);
    while (i < hlen) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
            if (j == nlen) {
                return i - j;
            }
        } else {
            if (0 == j) {
                i++;
            } else {
                j = next[j - 1];
            }
        }
    }
    return -1;
}

int strStrBruteForce(char *haystack, char *needle) {
    int pos = 0;
    int hlen = strlen(haystack);
    int nlen = strlen(needle);
    for (pos = 0; pos <= hlen - nlen; ++pos) {
        int p = 0;
        while (p < nlen && haystack[pos + p] == needle[p]) {
            p++;
        }
        if (p == nlen) {
            return pos;
        }
    }
    return -1;
}

void print_vector(const vector<int> v) {
    cout<<"  ["<<v[0];
    for(int i = 1; i < v.size(); ++i) {
        cout<<","<<v[i];
    }
    cout<<"]  ";
}

void testNextSimple(string needle, vector<int> next) {
    cout<<"Test next simple:  ";
    vector<int> output;
    get_next_simple(const_cast<char *>(needle.c_str()), output);
    bool pass_flag = true;
    if (output.size() == next.size()) {
        for (int i = 0; i < next.size(); ++i) {
            if (output[i] != next[i]) {
                pass_flag = false;
                break;
            }
        }
    } else {
        pass_flag = false;
    }
    if (pass_flag) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail ";
        print_vector(next);
        print_vector(output);
        cout<<endl;
    }
}

void testNext(string needle, vector<int> next) {
    cout<<"Test next:  ";
    vector<int> output;
    get_next(const_cast<char *>(needle.c_str()), output);
    bool pass_flag = true;
    if (output.size() == next.size()) {
        for (int i = 0; i < next.size(); ++i) {
            if (output[i] != next[i]) {
                pass_flag = false;
                break;
            }
        }
    } else {
        pass_flag = false;
    }
    if (pass_flag) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail ";
        print_vector(next);
        print_vector(output);
        cout<<endl;
    }
}

void testStrStr(string input1, string input2, int pos) {
    cout<<"Test strstr:  ";
    int outputBruteForce = strStrBruteForce(const_cast<char *>(input1.c_str()), const_cast<char *>(input2.c_str()));
    int output = strStr(const_cast<char *>(input1.c_str()), const_cast<char *>(input2.c_str()));
    if (outputBruteForce == output && output == pos) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail "<<pos<<" "<<output<<" "<<outputBruteForce<<endl;
    }
}

int main() {
    testStrStr("abcdft", "cdf", 2);    
    testStrStr("abcdft", "ecdf", -1);    
    
    int next1[] = {0,0,1,0,1,2};
    testNext("abacab", vector<int> (next1, next1 + 6));
    testNextSimple("abacab", vector<int> (next1, next1 + 6));
    
    return 0;
}

