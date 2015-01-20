#include <iostream>
#include "czqvector.h"
#include <algorithm>

using namespace std;

int maxArea(vector<int> &height) {
    int maxArea = 0;
    
    int left = 0;
    int right = height.size() - 1;
    maxArea = min(height[left], height[right]) * (right - left);
    int result;

    while (left < right) {
        if (height[left] < height[right]) {  // left is crucial
            left++;
        } else {  // right is crucial
            right--;
        }
        result = min(height[left], height[right]) * (right - left);
        maxArea = max(maxArea, result);
    }
    return maxArea;
}

void test(string inputstr, int result) {
    vector<int> input = build_int_vector(inputstr, ',');
    int output = maxArea(input);
    if (output == result) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail "<<output<<" "<<result<<endl;
    }
}

int main() {
    test("2,1,5,2,4", 8);

    return 0;
}

