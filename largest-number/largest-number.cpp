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
        return num1[min_len - 1] > num2[min_len];
    } else {
        return num2[min_len - 1] < num1[min_len];
    }
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
    for (int i = 0; i < num2str.size(); ++i) {
        ret.append(num2str[i]);
    }
    return ret;
}

int main() {
    vector<int> input = build_int_vector("3,30,34,5,9", ',');
    string output = largestNumber(input);
    cout<<output<<endl;
    return 0;
}

