#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
    // copy numbers
    vector<int> numbers_copy (numbers);
    // sort numbers
    sort(numbers.begin(), numbers.begin() + numbers.size());
    int head = 0;
    int tail = numbers.size() - 1;
    // find the lastest number that is smaller than target
    while (numbers[tail] > target) {
        tail--;
    }
    // tail >= head HERE
    int sum = 0;
    while (tail >= head) {
        sum = numbers[tail] + numbers[head];
        if (sum == target) {
            break;
        } else if (sum > target) {
            tail--;
        } else { // sum < target
            head++;
        }
    }
    
    int value_head = numbers[head];
    int value_tail = numbers[tail];

    vector<int>::iterator it_head = find(numbers_copy.begin(), numbers_copy.end(), value_head);
    vector<int>::iterator it_tail;
    if (value_tail == value_head) {
        it_tail = find(it_head + 1, numbers_copy.end(), value_tail);
    } else {
        it_tail = find(numbers_copy.begin(), numbers_copy.end(), value_tail);
    }

    int ret1 = it_head - numbers_copy.begin() + 1;
    int ret2 = it_tail - numbers_copy.begin() + 1;

    vector<int> ret;
    ret.push_back(ret1);
    ret.push_back(ret2);
    sort(ret.begin(), ret.end());
    return ret;
}

int testTwoSum(int numbers[], int length, int target, int results[]) {
    vector<int> input_numbers(numbers, numbers + length);
    int input_target = target;
    vector<int> output = twoSum(input_numbers, input_target);
    if (2 == output.size() && results[0] == output[0] && results[1] == output[1]) {
        cout<<"Pass"<<endl;
    } else {
        cout<<"Fail"<<endl;
        cout<<"Ouput: "<<output[0]<<" "<<output[1]<<endl;
    }
}

int main() {
    int num1[] = {2,7,11,15};
    int len1 = 4;
    int tar1 = 9;
    int ret1[] = {1,2};
    testTwoSum(num1, len1, tar1, ret1);
    
    int num2[] = {3,2,4};
    int len2 = 3;
    int tar2 = 6;
    int ret2[] = {2,3};
    testTwoSum(num1, len1, tar1, ret1);
    
    int num3[] = {-3,4,3,90};
    int len3 = 4;
    int tar3 = 0;
    int ret3[] = {1,3};
    testTwoSum(num3, len3, tar3, ret3);
    
    int num4[] = {5,75,25};
    int len4 = 3;
    int tar4 = 100;
    int ret4[] = {2,3};
    testTwoSum(num4, len4, tar4, ret4);
}
