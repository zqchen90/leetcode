# [Generate Parentheses ](https://oj.leetcode.com/problems/generate-parentheses/)

## Question
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

> "((()))", "(()())", "(())()", "()(())", "()()()"

## AC
2015-1-12

## Solution

### What is a well-formed parenthesis?

If s is a well-formed parenthesis, in s[0, .., i]:

  - The number of ( is always larger than the number of )

for any i.

### DFS

Write a function, which we will call recursively, the function construct well-formed parentheses with certain number of ( and ).

``` cpp
void add_parenthesis(int left, int right, string &path, vector<string> &ret) 
```

Assume the number of  ( is “left” and the number of ) is "right":

if left > 0, always try to append one ( to path, and call 
``` cpp
add_parenthesis(left-1, right, path, ret)
```
if right > left, try to append one ) to path, and call 
``` cpp
add_parenthesis(left, right - 1, path, ret)
```

Time: O(n^2)  ??

Space: O(n^2)  ??