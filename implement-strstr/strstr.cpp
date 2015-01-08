#include <iostream>

using namespace std;

int strStr(char *haystack, char *needle) {
    return -1;
}

int strStrBruteForce(char *haystack, char *needle) {
    int pos = 0;
    char *phay = haystack;
    char *pneedle = needle;
    while (haystack[pos] != '\0') {
        if (haystack[pos] == *pneedle) {
            char *phay = &haystack[pos];
            while (*phay == *pneedle && *phay != '\0' && *pneedle != '\0') {
                phay++;
                pneedle++;
            }
            if (*pneedle == '\0') {
                return pos;
            }
            pneedle = needle;
        }
        pos++;
    }
    return -1;
}

void testStrStr(string haystack, string needle, int pos) {
    string input1 (haystack);
    input1.append(1, '\0');
    string input2 (needle);
    input2.append(1, '\0');
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

