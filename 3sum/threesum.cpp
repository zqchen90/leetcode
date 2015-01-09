#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"

using namespace std;

void print(vector<vector<int> > &ret) {
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout<<ret[i][j]<<", ";
        }
        cout<<endl;
    }
}

vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > ret;
    int n = num.size();
    int target = 0;
    sort(num.begin(), num.end());
    int l, m, r;

    for (l = 0; l < n - 2 && num[l] <= 0; ++l) {
        if (l >= 1 && num[l] == num[l-1]) {
            continue;
        }
        m = l + 1;
        r = n - 1;
        while (m < r) {
            int sum = num[l] + num[m] + num[r];
            if (sum == target) {
                vector<int> tmp;
                tmp.push_back(num[l]);
                tmp.push_back(num[m]);
                tmp.push_back(num[r]);
                ret.push_back(tmp);
                r--;
                while (num[r] == num[r+1]) {
                    r--;
                }
            } else if (sum > target) {
                r--;
                while (num[r] == num[r+1]) {
                    r--;
                }
            } else {
                m++;
                while (num[m] == num[m-1]) {
                    m++;
                }
            }
        }
    }
    return ret;
}

int main() {
    int num[] = {-1,0,1,2,-1,-4};
    vector<int> numv (num, num + 6);
    vector<vector<int> > ret = threeSum(numv);
    print(ret);

    return 0;
}

