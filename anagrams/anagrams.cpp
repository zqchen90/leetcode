#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> anagrams(vector<string> &strs) {
    vector<string> ret;
    vector<string> strs_sort;
    unordered_map<int, vector<int> > length_index;
    int i = 0;
    int j = 0;
    // copy
    for (i = 0; i < strs.size(); ++i) {
        string tmp (strs[i]);
        strs_sort.push_back(tmp);

        vector<int> tmp_vector;
        length_index[strs[i].size()] = tmp_vector;
    }
    // sort
    for (i = 0; i < strs_sort.size(); ++i) {
        sort(strs_sort[i].begin(), strs_sort[i].end());
        length_index[strs_sort[i].size()].push_back(i);
    }
    // compare and add to ret
    for (auto it = length_index.begin(); it != length_index.end(); ++it) {
        for (int i = 0; i < it->second.size(); ++i) {
            bool add_flag = false;
            for (j = i + 1; j < strs.size(); ++j) {
                if (strs_sort[i] == strs_sort[j]) {
                    if (!add_flag) {
                        ret.push_back(strs[i]);
                        add_flag = true;
                    }
                    ret.push_back(strs[j]);
                }
            }
        }
    }
    /*
    for (i = 0; i < strs.size(); ++i) {
        bool add_flag = false;
        for (j = i + 1; j < strs.size(); ++j) {
            if (strs_sort[i].size() == strs_sort[j].size()) {
                if (strs_sort[i] == strs_sort[j]) {
                    if (!add_flag) {
                        ret.push_back(strs[i]);
                        add_flag = true;
                    }
                    ret.push_back(strs[j]);
                }
            }
        }
    }
    */
    return ret;
}

int main() {
    

    return 0;
}

