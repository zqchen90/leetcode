# [Construct Binary Tree from Preorder and Inorder Traversal ](https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

## Question
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
## AC
2015-1-8

## Solution

Preorder: root, left, right

Inorder: left, root, right

preorder[0] is the value of root and find it in inorder. Assume the index of root in inorder is i. So: 
 - inorder[0, ... , i-1] is the inorder traversal of the left tree
 - inorder[i+1, ... , n-1] is the inorder traversal of the right tree
 - preorder[1, ... , i] is the preorder traversal of the left tree
 - preorder[i+1, ... , n-1] is the preorder traversal of the right tree  

Time: O(n)

Space: O(n)