# [Scramble String](https://oj.leetcode.com/problems/scramble-string/)

## Question

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

```
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
```
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

```
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
```          

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

```
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
```

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.


## Solution

### DP

s1 and s2 are scramble when: 

1. there exist a l such that both (s1[0:l] and s2[0:l]) and (s1[l:end] and s2[l:end]) are scramble
2. OR there exist a l such that both (s1[0:l] and s2[l:end]) and (s1[l:end] and s2[0:l]) are scramble

dp[i][j][k] means which s1[i,...,i+k-1] and s2[j,...,j+k-1] is scramble or not, boolean.

dp[i][j][k] = (dp[i][j][l] && dp[i + l][j + l][k - l] || dp[i][j + k - l][l] && dp[i + l][j][k - l]) for any l (where to split, 1 <= l < k):

if split at l but don't swap:  dp[i][j][l] && dp[i + l][j + l][k - l]
if split at l and swap: dp[i][j + k - l][l] && dp[i + l][j][k - l]

Boundaries: dp[i][j][1] = (s1[i] == s2[j])

Time: O(n^4)

Space: O(n^3)