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

For number i:

i ^ (i >> 1)


Time: O(2^n)

Space: O(2^n) 