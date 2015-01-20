class Solution {
public:
    // Recursive solution will TLE
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        vector<int> count (n + 1, 0);
        count[1] = 1;
        count[2] = 2;
        
        for (int i = 3; i <= n; ++i) {
            count[i] = count[i-1] + count[i-2];
        }
        return count[n];
    }
};