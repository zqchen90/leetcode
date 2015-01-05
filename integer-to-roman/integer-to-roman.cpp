#include <iostream>
#include <string>

using namespace std;

string intDigitToRoman(int digit, string one, string five, string ten) {
    string ret = "";
    if (1 <= digit && 3 >= digit || 6 <= digit && 8 >= digit) {
        if (digit > 5) {
            ret.append(five);
            digit -= 5;
        }
        for (int i = 0; i < digit; ++i) {
            ret.append(one);
        }
    } else {
        switch(digit) {
            case 4: {
                ret.append(one);
                    }
            case 5: {
                ret.append(five);
                break;
                    }
            case 9: {
                ret.append(one);
                ret.append(ten);
                break;
                    }
        }
    }
    return ret;
}

string intToRoman(int num) {
    string one[] = {"I", "X", "C", "M", ""};
    string five[] = {"V", "L", "D", "", ""};
    string ret = "";

    int cur_carry = 1000;
    int carry = 10;
    int cur_digit = 4;

    int cnum = num;
    int remain = 0;
    while (cur_digit > 0) {
        remain = cnum % cur_carry;
        cnum = cnum / cur_carry;
        if (cnum > 0) {
            ret.append(intDigitToRoman(cnum, one[cur_digit - 1], five[cur_digit - 1], one[cur_digit]));
        }
        cnum = remain;
        cur_carry /= carry;
        cur_digit--;
    }
    return ret;
}

void testIntToRoman(int num, string roman) {
    string output = intToRoman(num);
    if (output == roman) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail "<<output<<" "<<roman<<endl;
    }
}

int main() {
    testIntToRoman(4, "IV");
    testIntToRoman(3, "III");
    testIntToRoman(9, "IX");
    testIntToRoman(40, "XL");
    testIntToRoman(207, "CCVII");
    testIntToRoman(1954, "MCMLIV");
    testIntToRoman(1990, "MCMXC");
    testIntToRoman(3999, "MMMCMXCIX");
    return 0;
}

