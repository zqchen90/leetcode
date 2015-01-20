# [Candy](https://oj.leetcode.com/problems/candy/)

## Question
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

 - Each child must have at least one candy.
 - Children with a higher rating get more candies than their neighbors.
 
What is the minimum candies you must give?
## AC
2015-1-20

## Solution

Need traversal ratings for two times:

1. The first time, check the element and its left side;
2. The second time, check the element and its right side. So the second traversal should from n-2 to 0.

Time: O(n)

Space: O(n)