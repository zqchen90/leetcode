# [Longest Consecutive Sequence ](https://oj.leetcode.com/problems/longest-consecutive-sequence/)
# Question
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,

Given [100, 4, 200, 1, 3, 2],

The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

# Solution

Traversal every element and check whetherits right and left sides to form a consecutive sequence are in the input. 

For example, if one element is 4, we should check 3,2,... and 5,6,7... and update the longest length.

Use unordered_map to make searching O(1).