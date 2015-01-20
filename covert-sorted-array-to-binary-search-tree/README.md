# [Convert Sorted Array to Binary Search Tree ](https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)

## Question
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

## AC
2015-1-11

## Solution

Pretty straight if you know what is BST. 

Find the middle element in the array, construct a node with it. Construct the left child tree using the elements in the left side in the array and the right child tree using the elements in the right side in the array recursively.

Time: O(n)

Space: O(n)