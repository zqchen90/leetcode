# [Three Sum Closest](https://oj.leetcode.com/problems/3sum-closest/)
## Question
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

>   For example, given array S = {-1 2 1 -4}, and target = 1
>   The sum that is closest to the target is 2 (-1 + 2 + 1 = 2)

## AC
2015-1-10

## Solution
Just the same as 3Sum
  1. Sort the array first.
  1. Use three pointers, left, middle, and right. Traversal left from 0 to n - 3.
  1. For each left, initialize middle = left + 1 and right = n - =
  1. Move "middle" right and move "right" left until they meet.
  1. When moving "middle" and "right", if they equal previous ones, they should be ignored directly.
  2. For each "left", "middle", and "right", calculate the sum and compare with closest sum at that time to see it needs to be updated or not.

Time: O(n^2)
Space: O(logn), because of quick sort.
