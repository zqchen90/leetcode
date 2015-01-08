#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n) {
    if (1 == n) {
        return "1";
    }
    string ret;
    string retp = countAndSay(n - 1);
    char c = retp.at(0);
    char c_cnt;
    int count = 1;
    for (int i = 1; i < retp.size(); ++i) {
        if (c == retp.at(i)) {
            count++;
        } else {
            c_cnt = count + '0';
            ret.append(1, c_cnt);
            ret.append(1, c);
            c = retp.at(i);
            count = 1;
        }
    }
    c_cnt = count + '0';
    ret.append(1, c_cnt);
    ret.append(1, c);

    return ret;
}

void testCountAndSay(int n, string result) {
    string output = countAndSay(n);
    if (output == result) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail"<<endl;
    }
}

int main() {
    testCountAndSay(2, "11");    
    testCountAndSay(3, "21");    
    testCountAndSay(4, "1211");    
    testCountAndSay(5, "111221");    
    return 0;
}

