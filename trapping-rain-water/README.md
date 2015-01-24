# Trapping Rain Water 

## Question

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

![](http://www.leetcode.com/wp-content/uploads/2012/08/rainwatertrap.png)

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. 

## Solution

### 1

1, Find the max bar in A[], max, max_index;

2, For i from 0 to max_index:
``` cpp
int prev = 0;
for (int i = 0; i < max_index; ++i) {
    if (A[i] > prev) {
        sum += (A[i] - prev) * (max_index - i);
        prev = A[i];
    }
    sum -= A[i];
}
```

3, For i from n-1 to max_index:
``` cpp
prev = 0;
for (int i = n - 1; i > max_index; --i) {
    if (A[i] > prev) {
        sum += (A[i] - prev) * (i - max_index);
        prev = A[i];
    }
    sum -= A[i];
}
```

trapping-rain-water.cpp


### 2

1. For each bar, find max_left, the max bar on its left side and max_right, the max bar on its right side;
2. For each bar, height = min(max_left[i], max_right[i]), the water on the top of this bar is height - A[i] if height is larger than A[i];
3. Sum water.
