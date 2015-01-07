#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// MUST use refer, or TLE will happen
bool has_key(const unordered_map<string, int> &map, const string &key) {
    unordered_map<string, int>::const_iterator it = map.find(key);
    if (it == map.end()) {
        return false;
    } else {
        return true;
    }
}

vector<string> anagrams(vector<string> &strs) {
    vector<string> ret;
    unordered_map<string, int> sort_string_index;
    int i = 0;
    int j = 0;
    // sort
    for (i = 0; i < strs.size(); ++i) {
        string s = strs[i];
        sort(s.begin(), s.end());
        if (has_key(sort_string_index, s)) {
            int index = sort_string_index[s];
            if (index >= 0) {
                ret.push_back(strs[index]);
                sort_string_index[s] = -1;
            }
            ret.push_back(strs[i]);
        } else {
            sort_string_index[s] = i;
        }
    }
    return ret;
}
int main() {
    

    return 0;
}

