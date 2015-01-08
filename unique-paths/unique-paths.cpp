class Solution {
public:
    int uniquePaths(int m, int n) {
        if (1 == m || 1 == n) {
            return 1;
        }
        if (2 == m && 2 == n) {
            return 2;
        }
        vector<vector<int> > dp (m + 1, vector<int> (n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (1 == i || 1 == j) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};