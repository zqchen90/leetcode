#include <iostream>
#include <vector>
#include "czqvector.h"

using namespace std;

int largestRectangleArea(vector<int> &height) {
    int maxArea = height[0];
    int left = 0;
    int right = height.size() - 1;
    for (int left = 0; left < height.size(); ++left) {
        int lowest = height[left];
        for (int right = left; right < height.size(); ++right) {
            if (lowest > height[right]) {
                lowest = height[right];
            }
            int area = lowest * (right - left + 1);
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }
    return maxArea;

}

void test(string inputstr, int result) {
    vector<int> input = build_int_vector(inputstr, ',');
    int output = largestRectangleArea(input);
    if (output == result) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail"<<output<<" "<<result<<endl;
    }
}

int main() {
    test("2,1,5,6,2,3", 10);
    test("2", 2);
    test("1,2,1,2,1,2,1", 7);
    return 0;
}

