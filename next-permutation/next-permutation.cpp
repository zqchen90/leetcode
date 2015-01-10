#include <iostream>
#include <vector>
#include <algorithm>
#include "print_vector.h"
#include "check_vector.h"

using namespace std;

void nextPermutation(vector<int> &num) {
    if (1 >= num.size()) {
        return;
    }
    int partition_number = num.size() - 2;
    while (partition_number >= 0) {
        if (num[partition_number] < num[partition_number + 1]) {
            break;
        }
        partition_number--;
    }
    if (partition_number < 0) {
        return reverse(num.begin(), num.end());
    }
    int change_number = num.size() - 1;
    while (change_number > partition_number) {
        if (num[change_number] > num[partition_number]) {
            break;
        }
        change_number--;
    }
    swap(num[change_number], num[partition_number]);
    reverse(num.begin() + partition_number + 1, num.end());
    return;
}

void testNextPermutation(vector<int> input, vector<int> output) {
    nextPermutation(input);
    if (check_vector(input, output)) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail, output: ";
        print_vector(input);
        cout<<" result: ";
        print_vector(output);
        cout<<endl;
    }
}

int main() {
    int input1[] = {1,2,3};
    int output1[] = {1,3,2};
    vector<int> inputv1 (input1, input1+3);
    vector<int> outputv1 (output1, output1+3);
    testNextPermutation(inputv1, outputv1);

    int input2[] = {1,1,3};
    int output2[] = {1,3,1};
    vector<int> inputv2 (input2, input2+3);
    vector<int> outputv2 (output2, output2+3);
    testNextPermutation(inputv2, outputv2);
     
    int input3[] = {1,1};
    int output3[] = {1,1};
    vector<int> inputv3 (input3, input3+2);
    vector<int> outputv3 (output3, output3+2);
    testNextPermutation(inputv3, outputv3);
    return 0;

}

