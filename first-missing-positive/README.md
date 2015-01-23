# [First Missing Positive ](https://oj.leetcode.com/problems/first-missing-positive/)

## Question
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

**Your algorithm should run in O(n) time and uses constant space.**


## AC
2015-1-21

## Solution

Traverse A for several rounds.

In each round, reduce the positive elements in A by one. If in any round, we can't find an element that equals to one, we know the number of round is the first missing positive integer.

I am not quite sure about the Time Complexity:

if A is like the first example given in the question, that is when A contains elements from 0 to n-1, it will cost O(n^2)
but n is much larger than the first missing positive, it will cost O(n)
But my code got AC and the runtime is 4ms.

Time: O(n) ?

Space: O(1) 

## Swap Solution

Try to put A[i] back to its order position A[A[i]-1], ignoring A[i] <= 0 and A[i] > n.

Then if we find A[i] != i + 1, we know the first missing positive is i + 1.

Time: O(n)

Space: O(1) 