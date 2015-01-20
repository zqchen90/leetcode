# [Distinct Subsequences](https://oj.leetcode.com/problems/distinct-subsequences/)

## Question
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
> S = "rabbbit", T = "rabbit"

Return 3.

## AC
2015-1-7

## Solution

### Task clarification

The statement in question is confusing. What the question means is to find subsequences in S, such that the subsequence is same as T. List some [examples](https://oj.leetcode.com/discuss/599/task-clarification) here:

Example 1: S = rabbbit, T = rabbit

> ra*bbit=T
rab*bit=T
ra*bbit=T

so there're totally 3.

Example 2:  S=rabb T=rab

> ra * b and rab *

Example 3: S=rsabb T=rab
> r * a * b and r * ab *

Example 4: S=rarab T=ra,

> ra\*, \*ra\*, and r\*a\*.

### DP

Define dp[i][j] as how many times T[0, ... j] can be found in S[0, ..., i] as sequences. So j <= i.

> if T[j] != S[i], dp[i][j]  =  dp[i - 1][j]
if T[j] == S[i], dp[i][j]  =  dp[i - 1][j] + dp[i - 1][j - 1]

How about the boundaries?

Because j <= i, so j == 0 is the only boundary.

if j == 0, dp[i][0] means how many times we can find T[0] in S[0, ..., i]:

> if T[0] != S[j], dp[i][0]  =  dp[i - 1][0]
if T[0] == S[j], dp[i][0]  =  dp[i - 1][0] + 1

return dp[S.size() - 1][T.size() - 1].

Time: O(m*n)

Space: O(m*n), m is the length of T and n is the length of S

### DP O(n) Space

Note that dp[i][j] is a 2D vector, but we only use the lower triangular of it. Besides, dp[i][j] only depends on dp[i - 1][j] and dp[i - 1]][j - 1].

We can use 1D vector dp1d to replace dp[i][j]:

- The length of dp1d is the length of T
- For any i, we fill dp1d from j = i to j = 0
- If S[i] == S[j], dp1d[j] += dp1d[j - 1]
