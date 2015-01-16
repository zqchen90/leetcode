# Largest Rectangle in Histogram 
## Question
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

![](http://www.leetcode.com/wp-content/uploads/2012/04/histogram.png)

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

![](http://www.leetcode.com/wp-content/uploads/2012/04/histogram_area.png)

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

## AC
2015-1-16

## Solution
The brute-force solution takes O(n^2) time complexity. Just traversal each bar as the left side and the right side of a rectangle and calculate the area. The code is in largest-rectangle-in-histogram-ON2.cpp. The code will TLE.

GeeksforGeeks provides [Divide and Conquer](http://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-set-1/) and a [O(n) solution](http://www.geeksforgeeks.org/largest-rectangle-under-histogram/).

largest-rectangle-in-histogram.cpp uses "Divide and Conquer" and gets AC.

### Divide and Conquer
The idea is to find the minimum value in the given array. Once we have index of the minimum value, the max area is maximum of following three values.
  1. Maximum area in left side of minimum value (Not including the min value)
  1. Maximum area in right side of minimum value (Not including the min value)
  1. Number of bars multiplied by minimum value.

If using linear search to find the minimum value, the worst time complexity is still O(n^2).

The is [algorithm, using Segment Tree](http://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/), to find range minimum in O(logn).

So the total time complexity is:
  - Build Segment tree: O(n)
  - Recursively find maximum area: O(nlogn)

Note that for this question, save the **index of the minimum value** in Segment tree.

### O(n) solution

TBD