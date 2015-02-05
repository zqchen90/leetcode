class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> subword_break (s.size() + 1, false);
        vector<vector<bool> > prev (s.size() + 1, vector<bool> (s.size() + 1, false));
        subword_break[0] = true;
        for (int subword_length = 1; subword_length <= s.size(); ++subword_length) {
            for (int break_at = subword_length - 1; break_at >= 0; --break_at) {
                if (subword_break[break_at] && 
                        isWord(s.substr(break_at, subword_length - break_at), dict)) {
                    subword_break[subword_length] = true;
                    prev[subword_length][break_at] = true;
                }
            }
        }
        
        vector<string> ret;
        vector<string> path;
        get_path(s, prev, s.size(), path, ret);
        return ret;
    }
    
private:
    bool isWord(string s, unordered_set<string> &dict) {
        if (dict.find(s) == dict.end()) {
            return false;
        } else {
            return true;
        }
    }
    
    void get_path(string s, vector<vector<bool> > &prev, int length,
                    vector<string> &path, vector<string> &ret) {
        if (0 == length) {
            string one_result = path[path.size() - 1];
            for (int i = path.size() - 2; i >= 0; --i) {
                one_result += " ";
                one_result += path[i];
            }
            ret.push_back(one_result);
            return;
        }
        
        for (int break_at = 0; break_at <= s.size(); ++break_at) {
            if (prev[length][break_at]) {
                path.push_back(s.substr(break_at, length - break_at));
                get_path(s, prev, break_at, path, ret);
                path.pop_back();
            }
        }
        
    }
};