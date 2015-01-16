#include <iostream>
#include <vector>
#include "range-minimum-query.h"
#include "segment_tree.h"

using namespace std;

void test(int inputarray[], int left, int right, int result) {
    vector<int> input (inputarray, inputarray + sizeof(inputarray) / sizeof(int));
    RangeMinimumQuery<int> query (input);
    query.initialize();
    int output = query.get_range_minimum_index(left, right);
    if (output == result) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail"<<output<<" "<<result<<endl;
    }
}

int main() {
    test({2,1,5,6,2,3}, 0, 5, 1);
    return 0;
}

