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

void add_result(vector<vector<int> > &ret, vector<int> &add) {
    for (int i = 0; i < ret.size(); ++i) {
        if (ret[i][0] == add[0] &&
            ret[i][1] == add[1] &&
            ret[i][2] == add[2]) {
            return;
        }
    }
    ret.push_back(add);
}

vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > ret;
    int n = num.size();
    int target = 0;
    sort(num.begin(), num.end());
    int l, m, r;

    for (l = 0; l < n - 2; ++l) {
        m = l + 1;
        r = n - 1;
        while (m < r) {
            int sum = num[l] + num[m] + num[r];
            if (sum == target) {
                vector<int> tmp;
                tmp.push_back(num[l]);
                tmp.push_back(num[m]);
                tmp.push_back(num[r]);
                add_result(ret, tmp); 
                r--;
            } else if (sum > target) {
                r--;
            } else {
                m++;
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

