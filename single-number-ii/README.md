# [Single Number II ](https://oj.leetcode.com/problems/single-number-ii/)

## Question
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

## Solution

Use a vector to remember the number of '1's appearing at every bit-position of a integer. This vector should has a length of sizeof(int) * 8 because one byte is made of 8 bits. We call it bitsCount.

If bitsCount[i] % 3 != 0, single number has an '1' at bit-position i.

Time: O(n)

Space: O(1)