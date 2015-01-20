# [Binary Tree Postorder Traversal](https://oj.leetcode.com/problems/binary-tree-postorder-traversal/)

## Question
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
 >  1
 >   \
 >    2
 >   /
 >  3

return [3,2,1].

**Note: Recursive solution is trivial, could you do it iteratively?**

## Solution

### Recursive
Simple

### Iterative
Use a stack and the only trick is when you pop a node from the stack, you don't know whether its children have or haven't been pushed into the stack.

So you need a flag for each node to mark whether the children of the node have been push in the stack or not.
 * If yes, pop the node;
 * If no, push the children.
