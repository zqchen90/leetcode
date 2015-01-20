# [Binary Tree Maximum Path Sum  ](https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/)
## Question
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,
 
  >   1
  >   / \
  >  2   3

Return 6.

## AC
2015-1-13

## Solution

Think it recursively:
  - Each node returns the maximum path value that begins or ends with itself
  - If we know the path value returned by left and right children, we can compare the following four paths: 
  (1) left -> current
  (2) current
  (3) current -> right
  (4) left -> current ->right
  - If (4) the maximum, we can't return its value because (4) neither starts nor ends with the current node. We only updates the global maximum with (4) and return the maximum among (1) - (3).
  - We must use a global variable to save the global maximum path value.

Time: O(n)

Space: O(logn)