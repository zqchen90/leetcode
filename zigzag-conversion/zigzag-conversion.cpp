#include <iostream>
#include <string>

using namespace std;

string convert(string s, int nRows) {
    if (s.size() <= nRows) {
        return s;
    }
    if (1 == nRows) {
        return s;
    }
    string ret = "";
    int first = 0;
    int second = 0;
    int interval = 2 * nRows - 2;
    // Row 0
    int pos = 0;
    while (pos < s.size()) {
        ret.append(1, s[pos]);
        pos += interval;
    }
    // Row 1 - (nRows - 2)
    for (int row = 1; row < nRows - 1; ++row) {
        int first = row;
        int second = interval - row;
        while (first < s.size() || second < s.size()) {
            if (first < s.size()) {
                ret.append(1, s[first]);
            }
            if (second < s.size()) {
                ret.append(1, s[second]);
            }
            first += interval;
            second += interval;
        }
    }
    // Row nRows - 1
    pos = nRows - 1;
    while (pos < s.size()) {
        ret.append(1, s[pos]);
        pos += interval;
    }
    return ret;
}

void testConvert(string input, int nRows, string result) {
    string output = convert(input, nRows);
    if (output == result) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail"<<" "<<output<<" "<<result<<endl;
    }
}

int main() {
    testConvert("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");    
    testConvert("PAYPALISHIRING", 4, "PINALSIGYAHRPI");    
    return 0;
}

