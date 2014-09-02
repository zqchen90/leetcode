#include <iostream>
#include <string>

using namespace std;

void addBit(char a, char b, int prevp, int *sum, int *p) {
    if (a == '0' && b == '0') {
        *sum = prevp;
        *p = 0;
        return;
    }
    if (a != b) {
        if (prevp == 0) { *sum = 1; *p = 0;}
        else { *sum = 0; *p = 1;}
        return;
    }
    if (a == '1' && b == '1') {
        if (prevp == 0) { *sum = 0; *p = 1;}
        else { *sum = 1; *p = 1;}
        return;
    }
}

string addBinary(string a, string b) {
    int alen = a.size();
    int blen = b.size();
    int sumlen = alen + 1;
    sumlen = alen > blen ? alen + 1 : blen + 1;
    int *suma = new int[sumlen];
    int sumbit = 0, p = 0, prevp = 0;
    char bit1, bit2;
    for (int i = 0; i < sumlen; i++) {
        if (i < alen) {
            bit1 = a[alen - 1 - i];
        } else {
            bit1 = '0';
        }
        if (i < blen) { bit2 = b[blen - 1 - i];}
        else { bit2 = '0';}
        addBit(bit1, bit2, prevp, &sumbit, &p);
        //cout<<bit1 - '0'<<" + "<<bit2 - '0'<<" = "<<sumbit<<","
        //    <<p<<endl;
        suma[sumlen - 1 - i] = sumbit;
        prevp = p;
    }
    string sum = "";
    int i = 0;
    const char one = '1';
    const char zero = '0';
    while (suma[i] == 0) { i++;}
    while (i < sumlen) {
        if (suma[i] == 1) { sum.append("1");}
        else {sum.append("0");}
        i++;
    }
    return sum;
}

int main() {
    string a = "11";
    string b = "1";
    cout<<addBinary(a, b)<<endl;

    return 0;
}

