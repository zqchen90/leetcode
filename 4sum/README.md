# [Four Sum](https://oj.leetcode.com/problems/4sum/)
## Question
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
  - Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
  - The solution set must not contain duplicate quadruplets.

>   For example, given array S = {1 0 -1 0 -2 2}, and target = 0
>   A solution set is:
>    (-1,  0, 0, 1)
>    (-2, -1, 1, 2)
>    (-2,  0, 0, 2)

## AC
2015-1-10

## Solution
Similar with 3Sum
  1. Sort the array first.
  1. Instead of three, we need four pointers, left, middle_left, middle_right and right. 
  2. Traverse left from 0 to n - 4 and middle_left from left + 1 to n - 3.
  1. For each pair of left and middle_left, initialize middle_right = middle_left + 1 and right = n - =
  1. Move "middle_right" right and move "right" left until they meet.
  1. Try to ignore equal elements when move four pointers.
  2. left, middle_left, middle_right, and right is in non-descending order, so when find sum == target, just add this quadruplet to result.

Time: O(n^3)
Space: O(logn), because of quick sort.
