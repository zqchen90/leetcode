#include <iostream>
#include <vector>
#include "czqvector.h"
#include <algorithm>

using namespace std;

void dfs(vector<int> &candidates, int start, int target, vector<int> &path, vector<vector<int> > &ret) {
    // cout<<"[ENTER] start: "<<start<<" target: "<<target<<endl;
    if (start >= candidates.size()) {
        return;
    }
    if (target < candidates[start]) {
        return;
    }
    int remain_target = target;
    int count = 0;
    // Use 0 current candidate
    int next_start = start + 1;
    for (; next_start < candidates.size(); ++next_start) {
        if (candidates[next_start] != candidates[next_start - 1]) {
            break;
        }
    }
    if (next_start < candidates.size()) {
        dfs(candidates, next_start, target, path, ret);
    }
    // Use 1 current candidate
    path.push_back(candidates[start]);
    remain_target -= candidates[start];
    if (remain_target == 0) {
        ret.push_back(path);
    } else {
        /*
        for (next_start = start  + 1; next_start < candidates.size(); ++next_start) {
            if (candidates[next_start] != candidates[next_start - 1]) {
                break;
            }
        }
        if (next_start < candidates.size()) {
            dfs(candidates, next_start, remain_target, path, ret);
        }
        */
        dfs(candidates, start + 1, remain_target, path, ret);
    }
    path.pop_back();
    // cout<<"[LEAVE] start: "<<start<<" target: "<<target<<endl;
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    // Sort candidates in descent order
    sort(candidates.begin(), candidates.end());
    
    vector<vector<int> > ret;
    vector<int> path;
    
    dfs(candidates, 0, target, path, ret);
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
    test("2,3,5", 7);
    test("1,2", 3);
    test("10,1,2,7,6,1,5", 8);
    return 0;
}

