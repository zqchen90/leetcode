class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> used;
        for (int i = 0; i < num.size(); ++i) {
            used[num[i]] = false;
        }
        int longest = 1;
        for (int i = 0; i < num.size(); ++i) {
            if (used[num[i]]) {
                continue;
            }
            int length = 1;
            used[num[i]] = true;
            // Try right side
            for (int j = num[i] + 1; ; j++) {
                if (used.find(j) == used.end()) {
                    break;
                } else {
                    length++;
                    used[j] = true;
                }
            }
            // Try left side
            for (int j = num[i] - 1; ; j--) {
                if (used.find(j) == used.end()) {
                    break;
                } else {
                    length++;
                    used[j] = true;
                }
            }
            // Update longest
            longest = max(longest, length);
        }
        return longest;
    }
};