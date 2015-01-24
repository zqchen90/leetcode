# [Interleaving String](https://oj.leetcode.com/problems/interleaving-string/)

## Question
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

## Solution

### Recursive

 - Step 1: If s1[start1] == s3[start3], find if s3[start3 + 1] is formed by the interleaving of s1[start1 + 1] and s2;

 - Step 2: If Step 1 fails, and if s2[start2] == s3[start3], find if s3[start3 + 1] is formed by the interleaving of s2[start2 + 1] and s1;

There are some places we can optimaze:

 - In above steps, we move forward one element once. But when s1[start1] == s1[start + 1] == ... == s1[start + k], we can move k elements.

This solution is interleaving-string.cpp and got AC on 2015-1-23 (Runtime 10ms).

### DP

bool dp[i][j] means whether s3[0, i+j] could be formed by the interleaving of s1[0, i] and s2[0, j]

 - dp[i][j] = dp[i - 1][j] if s1[i - 1] == s3 [i + j - 1];
 - dp[i][j] = dp[i][j - 1] if s2[j - 1] == s3 [i + j - 1];

To write two equations together:

dp[i][j] = (s1[i - 1] == s3 [i + j - 1] && dp[i - 1][j])
|| (s2[j - 1] == s3 [i + j - 1] && dp[i][j - 1]);

Time: O(n^2)

Space: O(n^2) 

Space can be reduced to O(n) using a rolling array because dp[i][j] only depends on d[i-1][j] and d[i][j-1].