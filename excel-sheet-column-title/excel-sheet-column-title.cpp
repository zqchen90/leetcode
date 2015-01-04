#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char itoA(int n) {
    return 'A' + n;
}

string convertToTitle(int n) {
    int ns = n;
    int carry = 26;
    string ret = "";
                            
    int remain = 0;
    while (ns > 0) {
        ns--;
        remain = ns % carry;
        string pos (1, itoA(remain));
        ret.append(pos);
        ns /= carry;
   }
                                            
   reverse(ret.begin(), ret.end());
   return ret;
}

void testConvertToTitle(int input, string result) {
    string output = convertToTitle(input);
    if (result == output) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail: "<<result<<"  "<<output<<endl;
    }
}

int main() {
    testConvertToTitle(27, "AA");
    testConvertToTitle(3, "C");
    testConvertToTitle(1, "A");
    testConvertToTitle(26, "Z");
    return 0;
}

