# [Best Time to Buy and Sell Stock II ](https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

## Question
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions 
as you like (ie, buy one and sell one share of the stock multiple times). However, **you may not engage in multiple transactions at the same time** (ie, you must sell the stock before you buy again).


## AC
2014-8-5

## Solution

We can gather all profits as long as prices[i + 1] > prices[i], which indicates we only keep the stock for one day.

Time: O(n)

Space: O(1)