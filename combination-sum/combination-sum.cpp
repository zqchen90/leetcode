#include <iostream>
#include <vector>
#include "czqvector.h"
#include <algorithm>

using namespace std;

void dfs(vector<int> &candidates, int start, int target, vector<int> &path, vector<vector<int> > &ret) {
    if (start >= candidates.size()) {
        return;
    }
    if (candidates[start] > target) {
        return;
    }
    int remain_target = target;
    int count = 0;
    while (remain_target >= candidates[start]) {
        path.push_back(candidates[start]);
        count += 1;
        remain_target -= candidates[start];
        if (remain_target == 0) {
            ret.push_back(path);
        } else {
            dfs(candidates, start + 1, remain_target, path, ret);
        }
    }
    while (count > 0) {
        path.pop_back();
        count -= 1;
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    // Sort candidates in descent order
    sort(candidates.begin(), candidates.end());
    reverse(candidates.begin(), candidates.end());
    
    // Ignore candidates larger than target
    int start = 0;
    for ( ; start < candidates.size(); ++start) {
        if (candidates[start] <= target) {
            break;
        }
    }

    vector<vector<int> > ret;
    vector<int> path;
    for ( ; start < candidates.size(); ++start) {
        dfs(candidates, start, target, path, ret);
    }
    return ret;
}

void test(string inputstr, int target) {
    vector<int> input = build_int_vector(inputstr, ',');
    vector<vector<int> > ret = combinationSum(input, target);
    print_2d_vector(ret);
    cout<<"--------"<<endl;
}

int main() {
    test("2,3,6,7", 7);

    return 0;
}

