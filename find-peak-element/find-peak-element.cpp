#include <iostream>
#include "czqvector.h"

using namespace std;

int findPeakElement(const vector<int> &num) {
    if (num.size() <= 1) {
        return 0;
    }
    int mid = 0;
    int left = 0;
    int right = num.size() - 1;
    while (left < right) {
        mid = (left + right) / 2;
        if (num[mid] > num[mid + 1]) {
            right = mid;
        } else if (num[mid] < num[mid + 1]) {
            left = mid + 1;
        }
    }
    return left;
}

void test(string inputstr, int result) {
    vector<int> input = build_int_vector(inputstr, ',');
    int output =  findPeakElement(input);
    if (output == result) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail "<<output<<" "<<result<<endl;
    }
}

int main() {
    test("1,2,3,1", 2);   

    return 0;
}

