# [Populating Next Right Pointers in Each Node II ](https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)

## Question
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note: You may only use constant extra space.

For example,

Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

## Solution

### Level-order-traversal
Traverse TreeLinkNodes in level order, the last node of each level connects to NULL.

This runtime is very fast but the space complexity is O(n).

poluting-next-right-pointers-in-each-node-ii.cpp, AC 2015-1-12, 38ms.

Time: O(n)

Space: O(n)

### Space O(1) solution

Similar to level-order-traversal, the O(1) solution has to process nodes level by level. Assume we are now at level k:

1. For any node at level k, who has both left and children, connect left to right child and remember the right child;
2. Jump to the next node at level k, and connect the previous right child to the current node's left child;
3. Remember the first node at level k+1, which is the first non-NULL child of level k.

poluting-next-right-pointers-in-each-node-ii.cpp, AC 2015-1-24, 41ms.

Time: O(n)

Space: O(1)


These two solutions can solve [Populating Next Right Pointers in Each Node](https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/) as well.