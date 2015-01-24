# [Max Points on a Line](https://oj.leetcode.com/problems/max-points-on-a-line/)

## Question
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

``` cpp
// Definition for a point.

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
```
## Solution

### Brute-force

There are n(n+1)/2 combinations of two points. Check the other n-2 points for each combination.

Time O(n^3)

Space O(1)

### Slope

There are n(n+1)/2 combinations of two points and there n(n+1)/2 slopes. Use an unordered_map to save (slope, # of combinations).

Time O(n^2)

Space O(n)