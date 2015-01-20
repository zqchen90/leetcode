# [Container With Most Water ](https://oj.leetcode.com/problems/container-with-most-water/)

## Question
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 

Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

## AC
2015-1-20

## Solution

Two pointers, one from head to tail and the other from tail to head.

Move the head pointer when the left wall is shorter, and move the tail pointer when the right wall is shorter.

For each move, update the maxArea is possible.


Time: O(n)

Space: O(1)

