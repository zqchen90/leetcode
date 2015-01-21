# [Gas Station](https://oj.leetcode.com/problems/gas-station/)

## Question
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

## AC
2014-9-20

## Solution

If the car starts at i and fails at k, then starting from any position    between i and k will fail. Because the car must arrive in any position [i, k) with a non-empty tank. So the next starting point should be k + 1.

The car only needs to move 2n times to cover all starting points. 

Be careful, the index of next gas station may be smaller, should use (i + 1) %n

Time: O(n)

Space: O(1)