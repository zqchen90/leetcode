# [Two Sum](https://oj.leetcode.com/problems/two-sum/)

## Question

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

## Solution

### Hash

Build unordered_map to save each number and its index.

For each number, just try to find target-number in the hash map.

Time: O(n)

Space: O(n)

### Sort

Sort the input and use two pointers, one move from left to right and the other from right to left.

Note that the indexs are required, so we need another vector to copy the input.

two-sum.cpp

Time: O(nlogn)

Space: O(n)
