#[Edit Distance](https://oj.leetcode.com/problems/edit-distance/submissions/)

## Question
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

## Solution

### DP

dp[i][j] is the edit distance between word1[0:i] and word2[0:j]

Obviously, dp[0][j] = j and dp[i][0] = i

if word1[i] == word2[j], dp[i][j] = dp[i - 1][j - 1]

else, dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])

Time: O(mn)

Space: O(mn) (Can be easily reduced to O(n) if only keep two rows of dp)