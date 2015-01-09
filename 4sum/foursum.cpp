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

vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> > ret;
    int n = num.size();
    sort(num.begin(), num.end());
    int l, ml, mr, r;

    for (l = 0; l < n - 3 && num[l] <= target; ++l) {
        if (l >= 1 && num[l] == num[l-1]) {
            continue;
        }
        for (ml = l + 1; ml < n - 2; ++ml) {
            if (ml > l + 1 && num[ml] == num[ml-1]) {
                continue;
            }
            mr = ml + 1;
            r = n - 1;
            while (mr < r) {
                int sum = num[l] + num[ml] + num[mr] + num[r];
                if (sum == target) {
                    vector<int> tmp;
                    tmp.push_back(num[l]);
                    tmp.push_back(num[ml]);
                    tmp.push_back(num[mr]);
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
                    mr++;
                    while (num[mr] == num[mr-1]) {
                        mr++;
                    }   
                }
            }
        }
    }
    return ret;
}

int main() {
    int num[] = {-1,0,1,0,-2,2};
    vector<int> numv (num, num + 6);
    vector<vector<int> > ret = fourSum(numv, 0);
    print(ret);

    return 0;
}

