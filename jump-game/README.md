# [Jump Game ](https://oj.leetcode.com/problems/jump-game/)

## Question
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

## Solution

Use "reach" to save the farthest position we could reach. We can reach the last index if "reach" is larger than n-1.

Try every position between 0 and "reach" to see if we can reach a farther position and update "reach".


Time: O(n)

Space: O(n) 