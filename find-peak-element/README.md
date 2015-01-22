# [Find Peak Element  ](https://oj.leetcode.com/problems/find-peak-element/)

## Question
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

**Note:Your solution should be in logarithmic complexity.**


## AC
2015-1-21

## Solution

Time complexities must be log(n) so we should think of binary search.

Please note two very import conditions:

1. num[i] ≠ num[i+1]
2. num[-1] = num[n] = -∞

which make binary search available for this question.

When finding the middle element num[mid], just compare num[mid] with num[mid + 1]:

  - if num[mid + 1] > num[mid], search the right side
  - else, search the left side.

Time: O(logn)

Space: O(1) 