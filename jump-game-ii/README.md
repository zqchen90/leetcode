#[Jump Game II](https://oj.leetcode.com/problems/jump-game-ii/)

## Quetion

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

##Solution

### DP
It is simple to solve the problem using DP:

D[i] is the minimum steps taken from i to the last index.

D[i] = min(D[j]) for each j in (i, i + A[i]]

An AC solution is jump-game-ii_DP_20150122_AC.cpp

### Greedy
Another approach is greedy at every jump.