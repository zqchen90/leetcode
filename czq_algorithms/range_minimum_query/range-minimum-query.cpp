#include <iostream>
#include <vector>
#include "range-minimum-query.h"
#include "segment_tree.h"

using namespace std;

template <typename T> void test(T inputarray[], int n, int left, int right, int result) {
    vector<T> input (inputarray, inputarray + n);
    //cout<<"Test input: "<<input.size()<<endl;
    RangeMinimumQuery<T> query (input);
    query.initialize();
    int output = query.get_range_minimum_index(left, right);
    if (output == result) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail"<<output<<" "<<result<<endl;
    }
}

int main() {
    cout<<"Test int"<<endl;
    int input1[] = {2,1,5,6,2,3};
    test(input1, sizeof(input1) / sizeof(int), 0, 5, 1);
    
    cout<<"Test int range"<<endl;
    test(input1, sizeof(input1) / sizeof(int), 2, 4, 4);
    
    cout<<"Test int out of range"<<endl;
    test(input1, sizeof(input1) / sizeof(int), 0, 7, -1);
    
    cout<<"Test negative int"<<endl;
    int input2[] = {2,1,-5,6,2,3};
    test(input2, sizeof(input2) / sizeof(int), 1, 4, 2);

    cout<<"Test double"<<endl;
    double input3[] = {2.3,4.3,0.89,87.92,2.0};
    test(input3, sizeof(input3) / sizeof(double), 1, 4, 2);
    
    cout<<"Test negative double"<<endl;
    double input4[] = {2.3,-4.3,0.89,87.92,2.0};
    test(input4, sizeof(input4) / sizeof(double), 0, 4, 1);
    
    cout<<"Test increasing double"<<endl;
    double input5[] = {2.3,4.3,8.9,87.92};
    test(input5, sizeof(input5) / sizeof(double), 0, 3, 0);
    return 0;
}

