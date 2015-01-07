#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> anagrams(vector<string> &strs) {
    vector<string> ret;
    vector<string> strs_sort;
    int i = 0;
    int j = 0;
    // copy
    for (i = 0; i < strs.size(); ++i) {
        string tmp (strs[i]);
        strs_sort.push_back(tmp);
    }
    // sort
    for (i = 0; i < strs_sort.size(); ++i) {
        sort(strs_sort[i].begin(), strs_sort[i].end());
    }
    // compare and add to ret
    for (i = 0; i < strs.size(); ++i) {
        bool add_flag = false;
        for (j = i + 1; j < strs.size(); ++j) {
            if (strs_sort[i] == strs_sort[j]) {
                if (!add_flag) {
                    ret.push_back(strs_sort[i]);
                }
                ret.push_back(strs_sort[j]);
            }
        }
    }
    return ret;
}

int main() {
    

    return 0;
}

