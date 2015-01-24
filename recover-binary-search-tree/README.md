#[Recover Binary Search Tree ](https://oj.leetcode.com/problems/recover-binary-search-tree/)

## Question
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

## Solution

### Straight forward O(n) space solution

It's easy to convert between a BST and a sorted array.

### O(1) space solution

Use Morris in-order traversal, the followings are the steps:

1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点（左孩子的最右侧孩子节点）。a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。
3. 重复以上1、2直到当前节点为空。


**How to detect a swapped node?**

Compare the prev and cur in in-order traversal, if prev->val > cur->val:

 - for the first time, prev is a swapped node
 - for the second time, cur is a swappped node

 Because when we swap node i and j (assuming i->val < j->val), j->val should be larger than its successor and i->val should be smaller than its successor.


Time: O(n)

Space: O(1)