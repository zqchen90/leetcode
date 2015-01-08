#include <iostream>
#include <string>
#include "string.h"

using namespace std;

int strStr(char *haystack, char *needle) {
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

void testStrStr(string input1, string input2, int pos) {
    int output = strStrBruteForce(const_cast<char *>(input1.c_str()), const_cast<char *>(input2.c_str()));
    if (output == pos) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail "<<pos<<" "<<output<<endl;
    }
}

int main() {
    testStrStr("abcdft", "cdf", 2);    
    testStrStr("abcdft", "ecdf", -1);    

    return 0;
}

