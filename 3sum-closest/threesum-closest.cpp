#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"

using namespace std;

int threeSumClosest(vector<int> &num, int target) {
    int n = num.size();
    int ret = num[0] + num[1] + num[2];
    sort(num.begin(), num.end());
    int l, m, r;

    for (l = 0; l < n - 2; ++l) {
        m = l + 1;
        r = n - 1;
        while (m < r) {
            int sum = num[l] + num[m] + num[r];
            if (sum == target) {
                return sum;
            } else if (sum > target) {
                r--;
            } else {
                m++;
            }
            if (abs(sum - target) < abs(ret - target)) {
                ret = sum;
            }
        }
    }
    return ret;
}

int main() {
    

    return 0;
}

