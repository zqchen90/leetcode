#include <iostream>
#include <string>
#include "czqstring.h"

using namespace std;

bool isInterleaveStartEnd(string s1, int start1, int end1,
                          string s2, int start2, int end2,
                          string s3, int start3, int end3) {
    if (start3 == end3) {
        if (start1 != end1 || start2 != end2) {
            return false;
        } else {
            return true;
        }
    }
    // s1 or s2 is empty
    if (start1 == end1) {
        return s2.substr(start2) == s3.substr(start3);
    }
    if (start2 == end2) {
        return s1.substr(start1) == s3.substr(start3);
    }
    // neither s1 nor s2 is empty
    bool isInterleaveS1;
    bool isInterleaveS2;
    if (s1[start1] == s3[start3]) {
        int newstart1 = start1;
        int newstart3 = start3;
        while (s1[newstart1] == s3[newstart3]) {
            newstart1++;
            newstart3++;
        }
        isInterleaveS1 = isInterleaveStartEnd(s1, newstart1, end1, s2, start2, end2, s3, newstart3, end3);
    }
    if (s2[start2] == s3[start3]) {
        int newstart2 = start2;
        int newstart3 = start3;
        while (s2[newstart2] == s3[newstart3]) {
            newstart2++;
            newstart3++;
        }
        isInterleaveS2 = isInterleaveStartEnd(s1, start1, end1, s2, newstart2, end2, s3, newstart3, end3);
    }
    if (s1[start1] == s3[start3] && s2[start2] == s3[start3]) {
        return isInterleaveS1 || isInterleaveS2;
    } else {
        if (s1[start1] == s3[start3]) {
            return isInterleaveS1;
        }
        if (s2[start2] == s3[start3]) {
            return isInterleaveS2;
        }
    }
    return false;
}

bool isInterleave(string s1, string s2, string s3) {
    return isInterleaveStartEnd(s1, 0, s1.size(), s2, 0, s2.size(), s3, 0, s3.size()); 
}

void test(string s1, string s2, string s3, bool result) {
    bool output =  isInterleave(s1, s2, s3);
    if (output == result) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail "<<output<<" "<<result<<endl;
    }
}

int main() {
    test("a", "b", "ab", true);
    test("aabcc", "dbbca", "aadbbcbcac", true);
    test("aabcc", "dbbca", "aadbbbaccc", false);
    return 0;
}
