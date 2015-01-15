#include <iostream>
#include <string>
#include <vector>
#include <sstream>  // ostringstream
#include "czqvector.h"
#include <algorithm>  // sort

using namespace std;

// return true if num1 > num2
// sort in descent order
bool my_compare(string num1, string num2) {
    /*
    if (num1.length() == num2.length()) {
        return num1 > num2;
    }
    int min_len = num1.length();
    bool num1_shorter = true;
    if (num2.length() < num1.length()) {
        min_len = num2.length();
        num1_shorter = false;
    }
    for (int i = 0; i < min_len; ++i) {
        if (num1[i] != num2[i]) {
            return num1[i] > num2[i];
        }
    }
    if (num1_shorter) {
        return num1[0] > num2[min_len];
    } else {
        return num2[0] < num1[min_len];
    }
    */
    string num1num2 = num1 + num2;
    string num2num1 = num2 + num1;
    return num1num2 > num2num1;
}

string int2string(int num) {
    ostringstream ss;
    ss<<num;
    return ss.str();
}

string largestNumber(vector<int> &num) {
    vector<string> num2str;
    for (int i = 0; i < num.size(); ++i) {
        num2str.push_back(int2string(num[i]));
    }
    // print_vector(num2str);
    sort(num2str.begin(), num2str.end(), my_compare);
    string ret ("");
    if (num2str[0] == "0") {
        return "0";
    }
    for (int i = 0; i < num2str.size(); ++i) {
        ret.append(num2str[i]);
    }
    return ret;
}

void testLargestNumber(string inputstr, string ret) {
    vector<int> input = build_int_vector(inputstr, ',');
    string output = largestNumber(input);
    if (output == ret) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail "<<output<<" " <<ret<<endl;
    }
}

int main() {
    testLargestNumber("3,30,34,5,9", "9534330");
    testLargestNumber("0,0", "0");
    testLargestNumber("824,938,1399,5607,6973,5703,9609,4398,8247", "9609938824824769735703560743981399");
    testLargestNumber("121,12", "12121");
    return 0;
}

