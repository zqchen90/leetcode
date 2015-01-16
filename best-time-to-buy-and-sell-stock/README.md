# [Best Time to Buy and Sell Stock ](https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/)
## Question
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

## AC
2014-8-5

## Solution

### Brute-force
For prices[i], find the maximum value in prices[i+1, ... , n-1], and update the max profit when buying at time i.

Time: $O(n^2)$

Space: O(1)

### Brute-force, O(1) maximum query
Use an array to save the maximum value, array[i] is the maximum value in prices[i+1, ... , n-1]. Fill the array from right to left only takes O(n) time.

Time: O(n)

Space: O(n)

### Optimal: One traversal

Use min to save the minimum price, and profit to save the current maximum profit.
Traversal prices from left to right:
  - if prices[i] < min, update min
  - if prices[i] - min > profit, update profit

Time: O(n)

Space: O(1)