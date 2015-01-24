# [Surrounded Regions ](https://oj.leetcode.com/problems/surrounded-regions/)

## Question

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

## Solution
 * Perform BFS from live 'O's on four edges and mark live 'O's as '+'
 * Scan the whole broad and change 'O' to 'X', '+' to 'O'

 Time: O(n^2)

 Space: O(n^2)
