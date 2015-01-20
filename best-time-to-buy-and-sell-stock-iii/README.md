# [Best Time to Buy and Sell Stock III ](https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)
## Question
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete **at most two transactions**.

Note:
**You may not engage in multiple transactions at the same time** (ie, you must sell the stock before you buy again).

## AC
2014-8-6

## Solution

At time i, the max profit equals to the sum of:
  1. Buy and sell at most once between [0, i]
  2. Buy and sell at most once between [i, n -1]


Use the code in [Best Time to Buy and Sell Stock](https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/) to calculate the max profit at time i.

Need two arrays "left" and "right" to save the above values.

For "left", i from 1 to n-1:
``` cpp
minPrice = min(minPrice, prices[i]);
left[i] = max(left[i - 1], left[i] - minPrice);
```

For "right", i n-2 to 0:
``` cpp
maxPrice = max(maxPrice, prices[i]);
right[i] = max(right[i + 1], maxPrice - prices[i]);
```

Return the maximum of left[i] + right[i].

Time: O(n)

Space: O(n)