# [Factorial Trailing Zeroes ](https://oj.leetcode.com/problems/factorial-trailing-zeroes/)

## Question
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

## AC
2015-1-7

## Solution

10 is the product of 2 and 5. In n!, we need to know how many 2 and 5, and the number of zeros
the minimum of the number of 2 and the number of 5.

Since multiple of 2 is more than multiple of 5, the number of zeros is dominant by the number of 5.

return n/5 + n/25 + n/125 + n/625 + n/3125+...;