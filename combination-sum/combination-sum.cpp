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
    dfs(candidates, start + 1, target, path, ret);
    while (remain_target >= candidates[start]) {
        path.push_back(candidates[start]);
        count += 1;
        remain_target -= candidates[start];
        if (remain_target == 0) {
            ret.push_back(path);
            // cout<<"Find one: ";
            // print_vector(path);
            // cout<<endl;
        } else {
            dfs(candidates, start + 1, remain_target, path, ret);
        }
    }
    while (count > 0) {
        path.pop_back();
        count -= 1;
    }
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
    test("7,3,2", 18);
    test("1,2", 3);
    return 0;
}

