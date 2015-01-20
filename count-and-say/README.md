# [Count and Say](https://oj.leetcode.com/problems/count-and-say/)

## Question
The count-and-say sequence is the sequence of integers beginning as follows:
> 1, 11, 21, 1211, 111221, ...

> 1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

## AC
2015-1-8

## Solution

The question is a little ambiguity, let's show some examples:

  - n = 1, should return 1
  - n = 2, should return 11
  - n = 5, should return 111221

The count-and-say sequence always starts with 1, not n.

And any time we see "111", we treat it as "three ones" not "one eleven".

If we know countAndSay(n - 1), how to get countAndSay(n):

Just count and say!


Time: O(n)

Space: O(n)

