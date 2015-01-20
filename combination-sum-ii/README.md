# [Combination Sum II](https://oj.leetcode.com/problems/combination-sum-ii/)

## Question
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
  - All numbers (including target) will be positive integers.
  - Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
  - The solution set must not contain duplicate combinations.
  - 
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
>[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6]
## AC
2015-1-20

## Solution

Deep First Search

Just few modifications from [Combination Sum](https://oj.leetcode.com/problems/combination-sum/). Suggest reading the solution of Combination Sum first.

Sort candidates first so we can ensure elements in a combination is in non-descent order.

### How to select combinations?

For each num[start], we can only select or not and then call the recursive dfs with start + 1.

However, this will result in duplicate combinations, take the candidate set in Question for example: there are two "1", so the results will have duplicate "1,7".

### How to avoid duplications?

In dfs, we have the following steps:

1. Not select this candidate, call dfs
2. Select this candidate, call dfs

If we decide not to select this candidate, we should skip all the duplicate candidates after it. Because we know we will select it in the second step. This will avoid duplications.