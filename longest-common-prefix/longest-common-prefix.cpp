class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        
    string ret("");

    if (0 == strs.size()) {

        return ret;

    }

    if (1 == strs.size()) {

        return strs[0];

    }

    for (int i = 0; i < strs[0].length(); ++i) {

        char c = strs[0][i];

        for (int j = 1; j < strs.size(); ++j) {

            if (strs[j][i] != c) {

                return ret;

            }

        }

        ret.append(1, c);

    }
    return ret;    

    }
};