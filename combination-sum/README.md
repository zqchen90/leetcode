# [Combination Sum](https://oj.leetcode.com/problems/combination-sum/)

## Question
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
  - All numbers (including target) will be positive integers.
  - Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
  - The solution set must not contain duplicate combinations.
 
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
> [7] 
[2, 2, 3] 
## AC
2015-1-20

## Solution

Deep First Search

Notations:
``` cpp
vector<vector<int> > ret;  // results
vector<int> path;  // a possible selection
int start;  // index of current candidate
```

Sort candidates first so we can ensure elements in a combination is in non-descent order.

How to select combinations?

Because candidate can be selected unlimited times, we can select the same candidate until the sum is larger the target. 

So we the recursive funtion:
``` cpp
dfs(candidate, start, target, path, ret)
```

We select candidate[start] for 0, 1, 2... time(s), for each selection, we push it into path and then call: 
``` cpp
dfs(candidate, start + 1, remain_target, path, ret)
```

Don't forget to pop all cadidate[start] out in the end of this function.

Any time remain_target == 0, we finish one combination and add path to ret.
