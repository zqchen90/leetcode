# [Three Sum](https://oj.leetcode.com/problems/3sum/)
## Question
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
  - Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
  - The solution set must not contain duplicate triplets.
>  For example, given array S = {-1 0 1 2 -1 -4},
>    A solution set is:
>    (-1, 0, 1)
>    (-1, -1, 2)

## AC
2015-1-10

## Solution
  1. Sort the array first.
  1. Use three pointers, left, middle, and right. Traversal left from 0 to n - 3.
  1. For each left, initialize middle = left + 1 and right = n - =
  1. Move "middle" right and move "right" left until they meet.
  1. When moving "middle" and "right", if they equal previous ones, they should be ignored directly.

Time O(n^2)
Space O(logn), because of quick sort.
