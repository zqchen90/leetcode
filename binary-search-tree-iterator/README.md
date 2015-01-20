# [Binary Search Tree Iterator ](https://oj.leetcode.com/problems/binary-search-tree-iterator/)
## Question
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.


## AC
2015-1-10

## Solution

The in-order traversal of BST returns a sorted sequence. next() returns the the successor of the current node in in-order traversal. But the direct method costs O(h) in time and O(1) in space.

If we can use O(h) space, we can use a stack:
 -  Initialize stack, push the root and all the left children of the left child tree;
``` cpp
TreeNode *p = root;
while (NULL != p) {
	s.push(p);
	p = p->left;
}
```
 -  When pops, push the right child (if not NULL), and the left children of left child tree of the right child.
``` cpp
TreeNode *p = s.top();
s.pop();
TreeNode *pr = p->right;
while (NULL != pr) {
	s.push(pr);
	pr = pr->left;
}
```
Time: O(1)

Space: O(h)