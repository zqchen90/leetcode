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

If s1[start1] == s3[start3], find if s3[start3 + 1] if formed by the interleaving of s1[start1 + 1] and s2;

If s2[start2] == s3[start3], find if s3[start3 + 1] if formed by the interleaving of s2[start2 + 1] and s1;

If s1[start1] == s3[start3] and s2[start2] == s3[start3], find if s3[start3 + 1] if formed by the interleaving of s2[start2 + 1] and s1 OR s1[start1 + 1] and s2.

This solution is interleaving-string.cpp and will get TLE. (updated 2015-1-23)

### DP



Time: O(n)

Space: O(n) 