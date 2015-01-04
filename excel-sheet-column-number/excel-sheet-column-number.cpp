#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int Atoi(char c) {
    return 1 + c - 'A';
}

int titleToNumber(string s) {
    string::reverse_iterator sp;
    int ret = 0;
    int carry = 26;
    int cur_carry = 1;
                                    
    for (sp = s.rbegin(); sp != s.rend(); ++sp) {
        int pos = Atoi(*sp);
        ret += pos * cur_carry;
        cur_carry *= carry;
    }                                       
    return ret;
}

void testConvertToTitle(int number, string title) {
    int output = titleToNumber(title);
    if (number == output) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail: "<<number<<"  "<<output<<endl;
    }
}

int main() {
    testConvertToTitle(27, "AA");
    testConvertToTitle(3, "C");
    testConvertToTitle(1, "A");
    testConvertToTitle(26, "Z");
    return 0;
}

