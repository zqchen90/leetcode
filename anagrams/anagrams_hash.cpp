#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool has_key(unordered_map<string, int> map, string key) {
    unordered_map<string, int>::const_iterator it = map.find(key);
    if (it == map.end()) {
        return false;
    } else {
        return true;
    }
}

vector<string> anagrams(vector<string> &strs) {
    vector<string> ret;
    vector<string> strs_sort;
    unordered_map<string, int> sort_string_index;
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
        if (has_key(sort_string_index, strs_sort[i])) {
            int index = sort_string_index[strs_sort[i]];
            if (index >= 0) {
                ret.push_back(strs[index]);
                index = -1;
            }
            ret.push_back(strs[i]);
        } else {
            sort_string_index[strs_sort[i]] = i;
        }
    }
    return ret;
}

int main() {
    

    return 0;
}

