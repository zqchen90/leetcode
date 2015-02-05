class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (isWord(s, dict)) return true;
        vector<bool> subword_break (s.size() + 1, false);
        subword_break[0] = true;
        for (int subword_length = 1; subword_length <= s.size(); ++subword_length) {
            for (int break_at = subword_length - 1; break_at >= 0; --break_at) {
                if (subword_break[break_at] && 
                        isWord(s.substr(break_at, subword_length - break_at), dict)) {
                    subword_break[subword_length] = true;
                    break;
                }
            }
        }
        
        return subword_break[s.size()];
    }
private:
    bool isWord(string s, unordered_set<string> &dict) {
        if (dict.find(s) == dict.end()) {
            return false;
        } else {
            return true;
        }
    }
};