# [Copy List with Random Pointer ](https://oj.leetcode.com/problems/copy-list-with-random-pointer/)

## Question
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

``` cpp
Definition for singly-linked list with a random pointer.
struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
```
## AC
2014-9-20

## Solution

Need two traversals:
1. Copy label and next;
2. Copy random, in this step, a map or unordered_map is needed to find certain nodes. The map should be constructed in step1.

Time: O(n)

Space: O(n)